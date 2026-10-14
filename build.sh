#!/usr/bin/env bash
# Compila el workspace (argumentos extra se pasan a colcon, p.ej. --packages-select pruebas_cpp)
set -e
cd "$(dirname "${BASH_SOURCE[0]}")"
source /opt/ros/lyrical/setup.bash
# compile_commands.json para IntelliSense de VS Code
export CMAKE_EXPORT_COMPILE_COMMANDS=ON
colcon build --symlink-install "$@"
