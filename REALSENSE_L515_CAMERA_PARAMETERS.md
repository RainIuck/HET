# Intel RealSense L515 Camera Parameters

This file records the factory calibration values read directly from the
currently connected Intel RealSense L515.

## Device Information

| Field | Value |
|---|---|
| Model | Intel RealSense L515 |
| Serial number | `f0264130` |
| Firmware version | `01.05.08.01` |
| Product ID | `0B64` |
| USB type | `3.2` |

## Depth Units

```text
depth_scale = 0.00025 meters per raw depth unit
ThinkGrasp CameraInfo.scale = 1 / depth_scale = 4000.0
```

Conversion formulas:

```text
depth_meters = depth_raw * 0.00025
depth_meters = depth_raw / 4000.0
```

Do not reuse ThinkGrasp's original `scale=1000.0` for this L515. Doing so
would make all reconstructed distances four times too large.

## ThinkGrasp Current Capture Configuration

The current `realsense_command_client.py` defaults to:

```text
Depth stream: 640x480, Z16, 30 FPS
Color stream: 640x480, BGR8, 30 FPS
Alignment: depth aligned to color
```

Because depth is aligned to color before being sent to ThinkGrasp, point-cloud
reconstruction should use the **Color 640x480** intrinsics:

```python
width = 640
height = 480
fx = 597.551574707031
fy = 598.061706542969
cx = 328.161956787109
cy = 233.166534423828
scale = 4000.0
```

Camera matrix:

```text
K_color_640x480 =
[[597.551574707031,   0.0,              328.161956787109],
 [  0.0,             598.061706542969,  233.166534423828],
 [  0.0,               0.0,                1.0           ]]
```

ThinkGrasp `CameraInfo`:

```python
CameraInfo(
    width=640,
    height=480,
    fx=597.551574707031,
    fy=598.061706542969,
    cx=328.161956787109,
    cy=233.166534423828,
    scale=4000.0,
)
```

## Depth Intrinsics

The native depth stream has no distortion according to the RealSense SDK.

### Depth 320x240

```text
fx = 228.228515625
fy = 229.111328125
cx = 157.310546875
cy = 127.107421875
distortion = None
coefficients = [0, 0, 0, 0, 0]
FOV = 70.06 x 55.25 degrees
```

### Depth 640x480

```text
fx = 457.7265625
fy = 457.43359375
cx = 315.05078125
cy = 255.189453125
distortion = None
coefficients = [0, 0, 0, 0, 0]
FOV = 69.91 x 55.33 degrees
```

Camera matrix:

```text
K_depth_640x480 =
[[457.7265625,    0.0,          315.05078125],
 [  0.0,          457.43359375, 255.189453125],
 [  0.0,            0.0,          1.0         ]]
```

### Depth 1024x768

```text
fx = 731.6015625
fy = 733.1640625
cx = 504.421875
cy = 409.24609375
distortion = None
coefficients = [0, 0, 0, 0, 0]
FOV = 69.97 x 55.24 degrees
```

## Color Intrinsics

All color profiles use the Brown-Conrady distortion model with:

```text
coefficients =
[0.168547853827477,
 -0.490009725093842,
 -0.000296413287287578,
 0.000575358106289059,
 0.441121011972427]
```

Coefficient order:

```text
[k1, k2, p1, p2, k3]
```

### Color 640x360

```text
fx = 448.163696289063
fy = 448.546295166016
cx = 326.121490478516
cy = 174.874893188477
FOV = 71.05 x 43.73 degrees
```

### Color 640x480

```text
fx = 597.551574707031
fy = 598.061706542969
cx = 328.161956787109
cy = 233.166534423828
FOV = 56.33 x 43.73 degrees
```

### Color 960x540

```text
fx = 672.245544433594
fy = 672.819458007813
cx = 489.182220458984
cy = 262.312347412109
FOV = 71.05 x 43.73 degrees
```

### Color 1280x720

```text
fx = 896.327392578125
fy = 897.092590332031
cx = 652.242980957031
cy = 349.749786376953
FOV = 71.05 x 43.73 degrees
```

### Color 1920x1080

```text
fx = 1344.49108886719
fy = 1345.63891601563
cx = 978.364440917969
cy = 524.624694824219
FOV = 71.05 x 43.73 degrees
```

## Depth-to-Color Extrinsics

The following transform maps points from the native depth coordinate frame to
the color coordinate frame.

Rotation matrix:

```text
R_depth_to_color =
[[ 0.999993,   -0.00355982,  0.00145399],
 [ 0.00351579,  0.999566,    0.0292407 ],
 [-0.00155745, -0.0292353,   0.999571  ]]
```

Translation vector in meters:

```text
t_depth_to_color =
[-0.000250668410444632,
  0.0141431130468845,
 -0.00379469920881093]
```

Transform convention:

```text
point_color = R_depth_to_color * point_depth + t_depth_to_color
```

## Usage Notes

- Use native depth intrinsics when reconstructing an unaligned depth image.
- Use color intrinsics when reconstructing a depth image produced by
  `rs.align(rs.stream.color)`.
- Intrinsics must match the exact stream resolution.
- The current ThinkGrasp real-world flow receives aligned `640x480` RGB-D
  images, so it should use the Color 640x480 intrinsics and `scale=4000.0`.
- ThinkGrasp currently ignores distortion coefficients. For maximum accuracy,
  use rectified images or RealSense SDK projection/deprojection functions.
- Re-read these parameters after replacing the camera. Intrinsics, extrinsics,
  and depth units are device-specific.
