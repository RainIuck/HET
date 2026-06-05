#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
WS_DIR="$(cd "${SCRIPT_DIR}/.." && pwd)"
LOG_ROOT="${WS_DIR}/experiment_logs/integration_debug"
LATEST_FILE="${LOG_ROOT}/latest_run_dir.txt"

usage() {
  cat <<EOF
Usage:
  tools/record_pick_integration.sh run
  tools/record_pick_integration.sh start
  tools/record_pick_integration.sh stop
  tools/record_pick_integration.sh status

The script records integration debug data under:
  ${LOG_ROOT}/pick_YYYYmmdd_HHMMSS
EOF
}

source_ros() {
  # ROS setup files may reference unset variables, so temporarily disable
  # nounset while sourcing them.
  set +u
  if [[ -f /opt/ros/humble/setup.bash ]]; then
    # shellcheck disable=SC1091
    source /opt/ros/humble/setup.bash
  fi
  if [[ -f "${WS_DIR}/install/setup.bash" ]]; then
    # shellcheck disable=SC1091
    source "${WS_DIR}/install/setup.bash"
  fi
  set -u
}

start_recording() {
  source_ros
  mkdir -p "${LOG_ROOT}"

  local stamp
  stamp="$(date +%Y%m%d_%H%M%S)"
  local run_dir="${LOG_ROOT}/pick_${stamp}"
  mkdir -p "${run_dir}"
  : > "${run_dir}/record_pids.txt"

  echo "${run_dir}" > "${LATEST_FILE}"

  ros2 topic echo /joint_states > "${run_dir}/joint_states.log" 2>&1 &
  echo "$!" >> "${run_dir}/record_pids.txt"

  ros2 topic echo /new_gripper/state > "${run_dir}/gripper_state.log" 2>&1 &
  echo "$!" >> "${run_dir}/record_pids.txt"

  ros2 topic echo /rosout > "${run_dir}/rosout.log" 2>&1 &
  echo "$!" >> "${run_dir}/record_pids.txt"

  python3 "${SCRIPT_DIR}/record_gripper_debug_state.py" \
    --log-root "${run_dir}/gripper_debug_state" \
    --print-every 0 \
    > "${run_dir}/gripper_debug_recorder.log" 2>&1 &
  echo "$!" >> "${run_dir}/record_pids.txt"

  {
    echo "created_at: $(date --iso-8601=seconds)"
    echo "workspace: ${WS_DIR}"
    echo "logs:"
    echo "  joint_states: joint_states.log"
    echo "  gripper_state: gripper_state.log"
    echo "  rosout: rosout.log"
    echo "  gripper_debug: gripper_debug_state/"
  } > "${run_dir}/metadata.txt"

  echo "recording to: ${run_dir}"
  echo "pid file: ${run_dir}/record_pids.txt"
}

stop_recording() {
  if [[ ! -f "${LATEST_FILE}" ]]; then
    echo "No latest run file: ${LATEST_FILE}"
    exit 1
  fi

  local run_dir
  run_dir="$(cat "${LATEST_FILE}")"
  local pid_file="${run_dir}/record_pids.txt"
  if [[ ! -f "${pid_file}" ]]; then
    echo "No pid file: ${pid_file}"
    exit 1
  fi

  while read -r pid; do
    if [[ -n "${pid}" ]] && kill -0 "${pid}" 2>/dev/null; then
      kill -INT "${pid}" 2>/dev/null || true
    fi
  done < "${pid_file}"

  sleep 1

  while read -r pid; do
    if [[ -n "${pid}" ]] && kill -0 "${pid}" 2>/dev/null; then
      kill "${pid}" 2>/dev/null || true
    fi
  done < "${pid_file}"

  echo "stopped recording: ${run_dir}"
}

run_recording() {
  start_recording
  local run_dir
  run_dir="$(cat "${LATEST_FILE}")"

  cleanup() {
    stop_recording || true
  }
  trap cleanup INT TERM EXIT

  echo "Recording is active. Press Ctrl-C to stop and save."
  while true; do
    sleep 1
  done
}

show_status() {
  if [[ ! -f "${LATEST_FILE}" ]]; then
    echo "No recording has been started."
    exit 0
  fi

  local run_dir
  run_dir="$(cat "${LATEST_FILE}")"
  echo "latest run: ${run_dir}"
  if [[ -f "${run_dir}/record_pids.txt" ]]; then
    while read -r pid; do
      if [[ -n "${pid}" ]] && kill -0 "${pid}" 2>/dev/null; then
        echo "running: ${pid}"
      else
        echo "stopped: ${pid}"
      fi
    done < "${run_dir}/record_pids.txt"
  fi
}

case "${1:-}" in
  run)
    run_recording
    ;;
  start)
    start_recording
    ;;
  stop)
    stop_recording
    ;;
  status)
    show_status
    ;;
  *)
    usage
    exit 1
    ;;
esac
