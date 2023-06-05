# turtle_bot_14
## _Developed by shalpy_

**turtle_bot_14** is a ROS2 package that allows the user to control a diferential robot mounted in a *Kuboki* base tested in the simulator CoppeliaSim.

This package has three nodes:
- turtle_bot_teleop
 - turtle_bot_player
- turtle_bot_interface


This package also depend on a custom service interface called:
- player_interfaces

This intercace has to be in the same */src* folder of your workspace when building the package.

## Running the code

To run the nodes within this package just include the package within the */src* folder of your workspace with its *player_interfaces* dependency srv package and compile it as it is shown:

```sh
cd /workspace
colcon build
. install/setup.bash
```

For running each node just run the following in your terminal:

```sh
ros2 run turtle_bot_14 turtle_bot_teleop
ros2 run turtle_bot_14 turtle_bot_player
ros2 run turtle_bot_14 turtle_bot_interface
```
The code for this proyect and some others in available [here](https://github.com/j-padillat/shalpy).