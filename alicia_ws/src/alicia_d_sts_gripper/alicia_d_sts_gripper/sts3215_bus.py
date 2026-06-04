import time
from dataclasses import dataclass
from typing import Optional

try:
    import serial
except ImportError as exc:  # pragma: no cover - handled at runtime on robot
    serial = None
    SERIAL_IMPORT_ERROR = exc
else:
    SERIAL_IMPORT_ERROR = None


class Sts3215Error(RuntimeError):
    pass


class Sts3215StatusError(Sts3215Error):
    def __init__(self, error_code: int, payload: bytes = b""):
        self.error_code = int(error_code) & 0xFF
        self.payload = bytes(payload)
        names = Sts3215Bus.status_error_names(self.error_code)
        detail = ", ".join(names) if names else "unknown"
        super().__init__(
            f"STS3215 status error 0x{self.error_code:02X} ({detail})"
        )


@dataclass
class Sts3215State:
    raw_position: Optional[int] = None
    target_position: Optional[int] = None
    position_error_direction: Optional[bool] = None
    position_error_ticks: Optional[int] = None
    moving: Optional[bool] = None
    voltage_v: Optional[float] = None
    temperature_c: Optional[int] = None
    load_raw: Optional[int] = None
    current_raw: Optional[int] = None


class Sts3215Bus:
    HEADER = b"\xff\xff"

    INST_PING = 0x01
    INST_READ = 0x02
    INST_WRITE = 0x03

    MODE_POSITION = 0
    MODE_VELOCITY = 1
    MODE_PWM = 2
    MODE_STEP = 3

    ADDR_MIN_ANGLE_LIMIT = 9
    ADDR_MAX_ANGLE_LIMIT = 11
    ADDR_OPERATING_MODE = 33
    ADDR_TORQUE_ENABLE = 40
    ADDR_ACCELERATION = 41
    ADDR_GOAL_POSITION = 42
    ADDR_GOAL_SPEED = 46
    ADDR_LOCK = 55
    ADDR_PRESENT_POSITION = 56
    ADDR_PRESENT_LOAD = 60
    ADDR_PRESENT_VOLTAGE = 62
    ADDR_PRESENT_TEMPERATURE = 63
    ADDR_MOVING = 66
    ADDR_TARGET_POSITION = 67
    ADDR_PRESENT_CURRENT = 69

    STATUS_ERROR_BITS = (
        (0x01, "voltage"),
        (0x02, "sensor"),
        (0x04, "temperature"),
        (0x08, "current"),
        (0x10, "angle"),
        (0x20, "overload"),
    )
    FATAL_STATUS_ERROR_MASK = 0x10

    def __init__(
        self,
        port: str,
        baudrate: int = 1000000,
        timeout: float = 0.1,
        write_timeout: Optional[float] = 1.0,
    ):
        if serial is None:
            raise Sts3215Error(f"python3-serial is not installed: {SERIAL_IMPORT_ERROR}")
        self.port = port
        self.baudrate = int(baudrate)
        self.timeout = float(timeout)
        self.write_timeout = (
            None if write_timeout is None else float(write_timeout)
        )
        self._serial = None

    @property
    def is_open(self) -> bool:
        return self._serial is not None and self._serial.is_open

    def open(self) -> None:
        if self.is_open:
            return
        self._serial = serial.Serial(
            self.port,
            self.baudrate,
            timeout=self.timeout,
            write_timeout=self.write_timeout,
        )
        self._serial.reset_input_buffer()
        self._serial.reset_output_buffer()

    def close(self) -> None:
        if self._serial is not None:
            self._serial.close()
            self._serial = None

    def _ensure_open(self) -> None:
        if not self.is_open:
            self.open()

    @staticmethod
    def _checksum(packet_tail) -> int:
        return (~sum(packet_tail)) & 0xFF

    @classmethod
    def status_error_names(cls, error_code: int):
        error_code = int(error_code) & 0xFF
        return [name for bit, name in cls.STATUS_ERROR_BITS if error_code & bit]

    def _packet(self, servo_id: int, instruction: int, params) -> bytes:
        params = list(params)
        length = len(params) + 2
        tail = [servo_id & 0xFF, length & 0xFF, instruction & 0xFF] + params
        return self.HEADER + bytes(tail + [self._checksum(tail)])

    def _write_packet(self, packet: bytes) -> None:
        self._ensure_open()
        try:
            self._serial.write(packet)
            self._serial.flush()
        except Exception as exc:
            raise Sts3215Error(f"Serial write failed on {self.port}: {exc}") from exc

    def _read_status_packet(self, expected_id: int) -> bytes:
        self._ensure_open()
        deadline = time.monotonic() + self.timeout

        window = bytearray()
        while time.monotonic() < deadline:
            byte = self._serial.read(1)
            if not byte:
                continue
            window += byte
            if len(window) > 2:
                window = window[-2:]
            if bytes(window) == self.HEADER:
                break
        else:
            raise Sts3215Error("Timed out waiting for STS3215 packet header")

        head = self._serial.read(3)
        if len(head) != 3:
            raise Sts3215Error("Incomplete STS3215 status header")
        servo_id, length, error = head
        params_and_checksum = self._serial.read(length - 1)
        if len(params_and_checksum) != length - 1:
            raise Sts3215Error("Incomplete STS3215 status payload")

        payload = list(head + params_and_checksum)
        checksum = payload[-1]
        if self._checksum(payload[:-1]) != checksum:
            raise Sts3215Error("STS3215 checksum mismatch")
        if servo_id not in (expected_id, 0xFE):
            raise Sts3215Error(f"Unexpected STS3215 id {servo_id}, expected {expected_id}")
        status_payload = bytes(params_and_checksum[:-1])
        fatal_error = error & self.FATAL_STATUS_ERROR_MASK
        if fatal_error:
            raise Sts3215StatusError(fatal_error, status_payload)

        return status_payload

    def ping(self, servo_id: int) -> bool:
        self._write_packet(self._packet(servo_id, self.INST_PING, []))
        self._read_status_packet(servo_id)
        return True

    def write_registers(self, servo_id: int, address: int, values) -> None:
        values = [int(v) & 0xFF for v in values]
        self._write_packet(self._packet(servo_id, self.INST_WRITE, [address & 0xFF] + values))

    def read_registers(self, servo_id: int, address: int, length: int) -> bytes:
        length = int(length)
        if length <= 0:
            raise Sts3215Error(f"Invalid STS3215 read length: {length}")
        self._write_packet(self._packet(servo_id, self.INST_READ, [address & 0xFF, length & 0xFF]))

        # STS3215 can return empty status packets for earlier write commands.
        # Skip those ACKs instead of mistaking one for this register read.
        short_payload_lengths = []
        short_status_errors = []
        for _ in range(32):
            try:
                payload = self._read_status_packet(servo_id)
            except Sts3215StatusError as exc:
                # A previous write can leave a zero-length ACK in the serial
                # buffer. Its alarm belongs to that earlier command, not to
                # this register read, so keep looking for the read response.
                if len(exc.payload) >= length:
                    raise
                short_payload_lengths.append(len(exc.payload))
                short_status_errors.append(str(exc))
                continue
            if len(payload) >= length:
                return payload
            short_payload_lengths.append(len(payload))

        raise Sts3215Error(
            "Did not receive STS3215 register data "
            f"address={address} length={length}; "
            f"short status payloads={short_payload_lengths}; "
            f"short status errors={short_status_errors}"
        )

    def read_u8(self, servo_id: int, address: int) -> int:
        data = self.read_registers(servo_id, address, 1)
        if len(data) < 1:
            raise Sts3215Error("u8 response too short")
        return data[0]

    def read_u16(self, servo_id: int, address: int) -> int:
        data = self.read_registers(servo_id, address, 2)
        if len(data) < 2:
            raise Sts3215Error("u16 response too short")
        return data[0] | (data[1] << 8)

    def write_u8(self, servo_id: int, address: int, value: int) -> None:
        self.write_registers(servo_id, address, [int(value) & 0xFF])

    def write_u16(self, servo_id: int, address: int, value: int) -> None:
        value = int(value) & 0xFFFF
        self.write_registers(servo_id, address, [value & 0xFF, (value >> 8) & 0xFF])

    def set_eeprom_lock(self, servo_id: int, locked: bool) -> None:
        self.write_u8(servo_id, self.ADDR_LOCK, 1 if locked else 0)

    def set_operating_mode(self, servo_id: int, mode: int, lock_after: bool = True) -> None:
        mode = int(mode)
        if mode not in (self.MODE_POSITION, self.MODE_VELOCITY, self.MODE_PWM, self.MODE_STEP):
            raise Sts3215Error(f"Unsupported STS3215 operating mode: {mode}")
        self.set_eeprom_lock(servo_id, False)
        self.write_u8(servo_id, self.ADDR_OPERATING_MODE, mode)
        if lock_after:
            self.set_eeprom_lock(servo_id, True)
        time.sleep(0.05)

    def read_operating_mode(self, servo_id: int) -> int:
        return self.read_u8(servo_id, self.ADDR_OPERATING_MODE)

    def set_angle_limits(self, servo_id: int, min_limit: int, max_limit: int, lock_after: bool = True) -> None:
        self.set_eeprom_lock(servo_id, False)
        self.write_u16(servo_id, self.ADDR_MIN_ANGLE_LIMIT, min_limit)
        self.write_u16(servo_id, self.ADDR_MAX_ANGLE_LIMIT, max_limit)
        if lock_after:
            self.set_eeprom_lock(servo_id, True)
        time.sleep(0.05)

    def enable_torque(self, servo_id: int, enable: bool) -> None:
        self.write_registers(servo_id, self.ADDR_TORQUE_ENABLE, [1 if enable else 0])

    def write_goal_position(
        self,
        servo_id: int,
        raw_position: int,
        speed: int = 800,
        acceleration: Optional[int] = 30,
        move_time: int = 0,
        max_position: int = 4095,
    ) -> None:
        raw_position = max(0, min(int(max_position), int(raw_position)))
        speed = max(0, min(4095, int(speed)))
        move_time = max(0, min(4095, int(move_time)))
        if acceleration is not None:
            self.write_registers(servo_id, self.ADDR_ACCELERATION, [max(0, min(255, int(acceleration)))])
        self.write_registers(
            servo_id,
            self.ADDR_GOAL_POSITION,
            [
                raw_position & 0xFF,
                (raw_position >> 8) & 0xFF,
                move_time & 0xFF,
                (move_time >> 8) & 0xFF,
                speed & 0xFF,
                (speed >> 8) & 0xFF,
            ],
        )

    def write_step_position(
        self,
        servo_id: int,
        relative_ticks: int,
        speed: int = 800,
        acceleration: Optional[int] = 30,
        move_time: int = 0,
    ) -> None:
        ticks = int(round(relative_ticks))
        magnitude = abs(ticks)
        if magnitude > 0x7FFF:
            raise Sts3215Error(f"Step command too large: {ticks}, expected -32767..32767")
        encoded = magnitude | (0x8000 if ticks < 0 else 0)
        self.write_goal_position(
            servo_id,
            encoded,
            speed=speed,
            acceleration=acceleration,
            move_time=move_time,
            max_position=0xFFFF,
        )

    def read_position(self, servo_id: int) -> int:
        data = self.read_registers(servo_id, self.ADDR_PRESENT_POSITION, 2)
        if len(data) < 2:
            raise Sts3215Error("Position response too short")
        return data[0] | (data[1] << 8)

    def read_target_position(self, servo_id: int) -> int:
        data = self.read_registers(servo_id, self.ADDR_TARGET_POSITION, 2)
        if len(data) < 2:
            raise Sts3215Error("Target position response too short")
        return data[0] | (data[1] << 8)

    def read_state(self, servo_id: int) -> Sts3215State:
        state = Sts3215State()
        state.raw_position = self.read_position(servo_id)
        state.position_error_direction = bool(state.raw_position & 0x8000)
        state.position_error_ticks = int(state.raw_position) & 0x7FFF

        try:
            state.target_position = self.read_target_position(servo_id)
        except Sts3215Error:
            pass

        try:
            data = self.read_registers(servo_id, self.ADDR_PRESENT_LOAD, 2)
            if len(data) >= 2:
                state.load_raw = data[0] | (data[1] << 8)
        except Sts3215Error:
            pass

        try:
            data = self.read_registers(servo_id, self.ADDR_PRESENT_VOLTAGE, 5)
            if len(data) >= 1:
                state.voltage_v = data[0] / 10.0
            if len(data) >= 2:
                state.temperature_c = data[1]
            if len(data) >= 5:
                state.moving = bool(data[4])
        except Sts3215Error:
            pass

        try:
            data = self.read_registers(servo_id, self.ADDR_PRESENT_CURRENT, 2)
            if len(data) >= 2:
                state.current_raw = data[0] | (data[1] << 8)
        except Sts3215Error:
            pass

        return state
