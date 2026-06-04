#!/usr/bin/env bash
set -euo pipefail

if [ "$#" -gt 0 ]; then
  BUSIDS=("$@")
elif [ -n "${ALICIA_USB_BUSID:-}" ]; then
  # Allow one or more busids, for example: ALICIA_USB_BUSID="2-3 2-5".
  # shellcheck disable=SC2206
  BUSIDS=(${ALICIA_USB_BUSID})
else
  BUSIDS=("2-3" "2-5")
fi
USBIPD_EXE="${USBIPD_EXE:-usbipd.exe}"

if ! command -v "${USBIPD_EXE}" >/dev/null 2>&1; then
  echo "ERROR: ${USBIPD_EXE} not found from WSL PATH." >&2
  echo "Install usbipd-win on Windows, then reopen WSL." >&2
  exit 1
fi

echo "Candidate USB busids: ${BUSIDS[*]}"
echo
echo "Current usbipd devices:"
"${USBIPD_EXE}" list || true
echo

ATTACH_RC=1
ATTACHED_BUSID=""
ATTACH_OUTPUT=""

for BUSID in "${BUSIDS[@]}"; do
  echo "Trying USB busid: ${BUSID}"
  set +e
  ATTACH_OUTPUT="$("${USBIPD_EXE}" attach --wsl --busid "${BUSID}" 2>&1)"
  ATTACH_RC=$?
  set -e

  printf '%s\n' "${ATTACH_OUTPUT}"

  if [ "${ATTACH_RC}" -eq 0 ]; then
    ATTACHED_BUSID="${BUSID}"
    break
  fi

  echo
done

if [ "${ATTACH_RC}" -ne 0 ]; then
  echo
  echo "ERROR: usbipd attach failed." >&2
  echo "If the device is not shared yet, run this in an Administrator PowerShell:" >&2
  echo "  usbipd bind --busid <BUSID>" >&2
  echo "Tried busids: ${BUSIDS[*]}" >&2
  echo "Then rerun this script from WSL." >&2
  exit "${ATTACH_RC}"
fi

echo
echo "Attached USB busid: ${ATTACHED_BUSID}"
echo
echo "Serial devices visible in WSL:"
if [ -d /dev/serial/by-id ]; then
  ls -l /dev/serial/by-id
else
  echo "/dev/serial/by-id does not exist yet. Try: ls /dev/ttyACM* /dev/ttyUSB*"
fi
