#!/usr/bin/env bash
set -u

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SETUP_FILE="${ROOT_DIR}/install_control2/setup.bash"
STAMP="$(date +%Y%m%d_%H%M%S)"
RUN_DIR="${ROOT_DIR}/experiment_logs/control_layer_${STAMP}"
ROS_LOG_DIR="${RUN_DIR}/ros_logs"

mkdir -p "${RUN_DIR}" "${ROS_LOG_DIR}"

if [[ ! -f "${SETUP_FILE}" ]]; then
  echo "Missing setup file: ${SETUP_FILE}" | tee "${RUN_DIR}/summary.txt"
  exit 2
fi

set +u
source "${SETUP_FILE}"
set -u
export ROS_LOG_DIR

PIDS=()

log() {
  echo "[$(date '+%F %T')] $*" | tee -a "${RUN_DIR}/summary.txt"
}

cleanup() {
  log "Cleaning up background ROS processes"
  for pid in "${PIDS[@]}"; do
    if kill -0 "${pid}" 2>/dev/null; then
      kill "${pid}" 2>/dev/null || true
    fi
  done
  sleep 2
  for pid in "${PIDS[@]}"; do
    if kill -0 "${pid}" 2>/dev/null; then
      kill -9 "${pid}" 2>/dev/null || true
    fi
  done
}

trap cleanup EXIT

wait_for_service() {
  local service_name="$1"
  local timeout_sec="$2"
  local started
  started="$(date +%s)"

  while true; do
    if ros2 service list 2>/dev/null | grep -qx "${service_name}"; then
      log "Service ready: ${service_name}"
      return 0
    fi

    if (( "$(date +%s)" - started >= timeout_sec )); then
      log "Timed out waiting for service: ${service_name}"
      return 1
    fi

    sleep 1
  done
}

snapshot() {
  local label="$1"
  log "Writing snapshot: ${label}"
  {
    echo "===== ros2 node list ====="
    ros2 node list
    echo
    echo "===== ros2 service list ====="
    ros2 service list
    echo
    echo "===== ros2 topic list ====="
    ros2 topic list
    echo
    echo "===== ros2 control list_controllers ====="
    ros2 control list_controllers
    echo
    echo "===== one joint_states message ====="
    timeout 5s ros2 topic echo --once /joint_states || true
  } > "${RUN_DIR}/${label}.txt" 2>&1
}

log "Experiment directory: ${RUN_DIR}"
log "Starting MoveIt demo launch"
ros2 launch alicia_d_moveit demo.launch.py gripper_type:=50mm > "${RUN_DIR}/moveit_demo.log" 2>&1 &
PIDS+=("$!")

wait_for_service /compute_ik 90 || exit 10
wait_for_service /plan_kinematic_path 90 || exit 11

log "Recording /joint_states"
timeout 120s ros2 topic echo /joint_states > "${RUN_DIR}/joint_states.log" 2>&1 &
PIDS+=("$!")

snapshot "before_mock_pick"

BRIDGE_PREFIX="$(ros2 pkg prefix alicia_d_thinkgrasp_bridge)"
CONFIG_FILE="${BRIDGE_PREFIX}/share/alicia_d_thinkgrasp_bridge/config/mock_grasp.yaml"

log "Starting mock ThinkGrasp decision server"
ros2 run alicia_d_thinkgrasp_bridge mock_decision_server.py \
  --ros-args --params-file "${CONFIG_FILE}" > "${RUN_DIR}/mock_server.log" 2>&1 &
PIDS+=("$!")

sleep 2

log "Running mock ThinkGrasp pick with execute_motion=true"
set +e
timeout 90s ros2 run alicia_d_thinkgrasp_bridge thinkgrasp_mock_pick.py \
  --ros-args --params-file "${CONFIG_FILE}" -p execute_motion:=true > "${RUN_DIR}/mock_pick.log" 2>&1
MOCK_RC=$?
set -e

snapshot "after_mock_pick"

if [[ "${MOCK_RC}" -eq 0 ]]; then
  log "Mock pick launch exited successfully"
else
  log "Mock pick launch exited with code ${MOCK_RC}"
fi

log "Done"
exit "${MOCK_RC}"
