#!/bin/usr/env bash

wget http://beru.univ-brest.fr/svn/CHEDDAR/releases/Cheddar-3.2-Linux64-bin.tar.gz

tar xfvz Cheddar-3.2-Linux64-bin.tar.gz
mkdir -p ${HOME}/.local/opt
mv Cheddar-3.2-Linux64-bin ${HOME}/.local/opt/

sed -i '/^export CHEDDAR_INSTALL_PATH=/d' ${HOME}/.local/opt/Cheddar-3.2-Linux64-bin/cheddar.bash

cat << EOF >> ${HOME}/.bash_profile
export CHEDDAR_INSTALL_PATH=${HOME}/.local/opt/Cheddar-3.2-Linux64-bin/
alias run-cheddar='source \${CHEDDAR_INSTALL_PATH}cheddar.bash && cheddar'
EOF

export CHEDDAR_INSTALL_PATH=${HOME}/.local/opt/Cheddar-3.2-Linux64-bin/
alias run-cheddar='source ${CHEDDAR_INSTALL_PATH}cheddar.bash && cheddar'
