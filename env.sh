#!/usr/bin/env bash
# Uso: source env.sh
# Carga ROS 2 Lyrical y, si existe, el overlay de este workspace.
_WS_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
source /opt/ros/lyrical/setup.bash
if [ -f "$_WS_DIR/install/setup.bash" ]; then
    source "$_WS_DIR/install/setup.bash"
fi
# Dominio propio para no interferir con otros nodos de la red/máquina
export ROS_DOMAIN_ID=${ROS_DOMAIN_ID_PRUEBAS:-42}
echo "ROS_DISTRO=$ROS_DISTRO  ROS_DOMAIN_ID=$ROS_DOMAIN_ID  WS=$_WS_DIR"
unset _WS_DIR
