#!/bin/bash
export LD_PRELOAD="$PWD/hijack.so"
eval "$*"
export LD_PRELOAD=
