#!/bin/sh
#
# Copyright (C) 2013-2014, Nanjing StarOS Technology Co., Ltd
#
CURRENT=`pwd`
export ROOTDIR=$CURRENT/../

export USER_ROOT=$CURRENT/../

export BUILD_NUMBER=1

export OPENBRAS_VERSION="1.0.0"

export OPENBRAS_STAGE_ROOT=/tmp
export OPENBRAS_RPM_ROOT=$OPENBRAS_STAGE_ROOT/rpm
export OPENBRAS_RPM_VERSION=${OPENBRAS_VERSION//-/.}
export OPENBRAS_STAGE=$CURRENT/openbras


export ACE_ROOT=$USER_ROOT/src/ace/ACE_wrappers
export ACE_LIB_PATH=$ACE_ROOT/lib
export ACE_INCLUDE=$ACE_ROOT
export INSTALL_PREFIX=$USER_ROOT/src/ace/install
export OPENBRAS_LIB_PATH=$USER_ROOT/libs
LD_LIBRARY_PATH=$ACE_LIB_PATH:$OPENBRAS_LIB_PATH:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH