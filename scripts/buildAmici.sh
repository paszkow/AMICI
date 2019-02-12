#!/bin/bash
#
# Build libamici
#
set -e

SCRIPT_PATH=$(dirname $BASH_SOURCE)
AMICI_PATH=$(cd $SCRIPT_PATH/.. && pwd)

mkdir -p ${AMICI_PATH}/build
cd ${AMICI_PATH}/build
CPPUTEST_BUILD_DIR=${AMICI_PATH}/ThirdParty/cpputest-master/build/
CppUTest_DIR=${CPPUTEST_BUILD_DIR} cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_PYTHON=OFF ..
make -j

make python-sdist
set -x
