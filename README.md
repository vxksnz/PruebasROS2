# PruebasROS — workspace de pruebas ROS 2 Lyrical

Ubuntu 26.04 · ROS 2 Lyrical (`/opt/ros/lyrical`) · C++ (g++ 15, CMake 4)

## Uso rápido

```bash
cd ~/Documents/PruebasROS
./build.sh                 # colcon build --symlink-install (acepta args extra de colcon)
source env.sh              # carga Lyrical + este workspace, ROS_DOMAIN_ID=42

ros2 run pruebas_cpp talker     # terminal 1
ros2 run pruebas_cpp listener   # terminal 2
```

## Estructura

```
src/pruebas_cpp/       paquete ament_cmake de ejemplo (talker / listener en /chatter + test gtest)
env.sh                 entorno (usar con `source`)
build.sh               compilación
build/ install/ log/   generados por colcon (ignorados en git)
```

## Notas

- `ROS_DOMAIN_ID` es 42 por defecto para aislar las pruebas; cámbialo con
  `ROS_DOMAIN_ID_PRUEBAS=<n> source env.sh`.
- Nuevo paquete: `cd src && ros2 pkg create --build-type ament_cmake --dependencies rclcpp <nombre>`.
- Dependencias de paquetes: `rosdep install --from-paths src -y --ignore-src`.
- Tests: `colcon test && colcon test-result --verbose` (gtest en `test/`).
- En C++ hay que recompilar (`./build.sh`) tras cada cambio de código.
- VS Code: IntelliSense usa `build/compile_commands.json` (lo genera `./build.sh`); si un include sale en rojo, recompila y ejecuta "C/C++: Reset IntelliSense Database".
- `log/` solo guarda registros de colcon; se puede borrar cuando quieras.
