#!/usr/bin/env python3
import json
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer

import rclpy


class MockDecisionHandler(BaseHTTPRequestHandler):
    response_payload = {}

    def do_POST(self):
        if self.path != "/grasp_pose":
            self.send_error(404, "Only /grasp_pose is supported")
            return

        content_length = int(self.headers.get("Content-Length", "0"))
        if content_length:
            self.rfile.read(content_length)

        body = json.dumps(self.response_payload).encode("utf-8")
        self.send_response(200)
        self.send_header("Content-Type", "application/json")
        self.send_header("Content-Length", str(len(body)))
        self.end_headers()
        self.wfile.write(body)

    def log_message(self, fmt, *args):
        print("[mock_decision_server] " + fmt % args)


def main(args=None):
    rclpy.init(args=args)
    node = rclpy.create_node("mock_decision_server")

    node.declare_parameter("host", "127.0.0.1")
    node.declare_parameter("port", 5000)
    node.declare_parameter("xyz", [0.35, 0.0, 0.22])
    node.declare_parameter("rot_flat", [-1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, -1.0])
    node.declare_parameter("dep", 0.04)

    host = node.get_parameter("host").value
    port = int(node.get_parameter("port").value)
    xyz = [float(v) for v in node.get_parameter("xyz").value]
    rot_flat = [float(v) for v in node.get_parameter("rot_flat").value]
    if len(rot_flat) != 9:
        raise ValueError("rot_flat must contain 9 numbers")
    rot = [rot_flat[0:3], rot_flat[3:6], rot_flat[6:9]]
    dep = float(node.get_parameter("dep").value)

    MockDecisionHandler.response_payload = {
        "xyz": xyz,
        "rot": rot,
        "dep": dep,
    }

    server = ThreadingHTTPServer((host, port), MockDecisionHandler)
    node.get_logger().info(f"Mock ThinkGrasp server listening on http://{host}:{port}/grasp_pose")
    node.get_logger().info(f"Response payload: {MockDecisionHandler.response_payload}")

    try:
        server.serve_forever()
    except KeyboardInterrupt:
        pass
    finally:
        server.server_close()
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()
