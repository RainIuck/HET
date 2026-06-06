# Camera Coordinate System

## Coordinate Frames

The camera frame follows the ThinkGrasp image convention:

- Camera `+X`: image right, along the 640-pixel image dimension.
- Camera `+Y`: image down, along the 480-pixel image dimension.
- Camera `+Z`: camera viewing direction.

The MoveIt arm end-effector frame is `gripper_center`. Relative to
`gripper_center`, the camera axes are:

- Camera `+X` corresponds to end-effector `-Y`.
- Camera `+Y` corresponds to end-effector `-X`.
- Camera `+Z` corresponds to end-effector `-Z`.

The camera origin position in the end-effector frame is:

```text
p_end_camera = [0.085, 0, -0.030] m
```

## End-Effector To Camera Transform

The camera pose relative to `gripper_center` is:

```text
T_end_camera =
[  0  -1   0    0.085 ]
[ -1   0   0    0     ]
[  0   0  -1   -0.030 ]
[  0   0   0    1     ]
```

This transform converts a point from the camera frame to the end-effector
frame:

```text
p_end = T_end_camera * p_camera
```

Expanded:

```text
x_end = -y_camera + 0.085
y_end = -x_camera
z_end = -z_camera - 0.030
```

The inverse transform is:

```text
T_camera_end =
[  0  -1   0    0     ]
[ -1   0   0    0.085 ]
[  0   0  -1   -0.030 ]
[  0   0   0    1     ]
```

## Fixed Capture Joint Pose

The fixed capture pose is configured in:

```text
alicia_ws/src/alicia_d_pick_coordinator/config/waypoints.yaml
```

The configuration stores values in this order:

```text
[Joint2, Joint3, Joint1, Joint4, Joint6, Joint5]
```

Recorded values:

```text
[ 0.09357282806102418,
  1.4143302864305616,
 -0.0015339807878858025,
  0.003067961575771161,
  0.003067961575771161,
  0.8851069146100148 ]
```

Reordered into the forward-kinematics order `[Joint1, Joint2, Joint3,
Joint4, Joint5, Joint6]`:

```text
[ -0.0015339807878858025,
   0.09357282806102418,
   1.4143302864305616,
   0.003067961575771161,
   0.8851069146100148,
   0.003067961575771161 ]
```

All joint values are in radians.

## Camera Pose At Fixed Capture Position

The base-to-camera transform is calculated as:

```text
T_base_camera = T_base_end * T_end_camera
```

At the fixed capture joint pose:

```text
T_base_camera =
[ 0.006532625004   0.999974244734   0.002972318743  -0.265520454171 ]
[ 0.999975508797  -0.006540040241   0.002491922780   0.000130396479 ]
[ 0.002511297684   0.002955967150  -0.999992477793   0.693189415819 ]
[ 0                0                0                1              ]
```

This transform converts camera-frame points into the robot base frame:

```text
p_base = T_base_camera * p_camera
```

The camera position in `base_link` is:

```text
position_xyz_m =
[-0.265520454171, 0.000130396479, 0.693189415819]
```

The camera orientation in `base_link` is:

```text
rpy_rad =
[3.138636672814, -0.002511300324, 1.564263634727]

rpy_deg =
[179.830634777, -0.143886910, 89.625704316]

quaternion_xyzw =
[0.709412634339, 0.704790715842, 0.001932449523, 0.000163531190]
```

The columns of the rotation matrix show the camera axes in `base_link`:

```text
camera +X in base_link =
[0.006532625004, 0.999975508797, 0.002511297684]
approximately base_link +Y

camera +Y in base_link =
[0.999974244734, -0.006540040241, 0.002955967150]
approximately base_link +X

camera +Z in base_link =
[0.002972318743, 0.002491922780, -0.999992477793]
approximately base_link -Z
```

Therefore, at the fixed capture pose, the camera looks almost vertically
downward.

## Base To Camera Point Conversion

For a camera-frame point:

```text
p_camera = [x_camera, y_camera, z_camera, 1]^T
```

calculate its position in `base_link` with:

```text
p_base = T_base_camera * p_camera
```

Expanded:

```text
x_base =
  0.006532625004 * x_camera
+ 0.999974244734 * y_camera
+ 0.002972318743 * z_camera
- 0.265520454171

y_base =
  0.999975508797 * x_camera
- 0.006540040241 * y_camera
+ 0.002491922780 * z_camera
+ 0.000130396479

z_base =
  0.002511297684 * x_camera
+ 0.002955967150 * y_camera
- 0.999992477793 * z_camera
+ 0.693189415819
```

All position values use meters.

## Related Files

- Forward-kinematics tool: `alicia_ws/tools/alicia_fk.py`
- Capture joint pose: `alicia_ws/src/alicia_d_pick_coordinator/config/waypoints.yaml`
- Robot URDF: `alicia_ws/src/alicia_d_descriptions/urdf/Alicia_D_v5_6/Alicia_D_v5_6_gripper_50mm.urdf`
- MoveIt SRDF: `alicia_ws/src/alicia_d_moveit/config/Alicia_D_v5_6_gripper_50mm.srdf`

The values above are calculated from the current URDF and the manually
specified camera mounting transform. Physical mounting and URDF modeling
errors may require later hand-eye calibration.
