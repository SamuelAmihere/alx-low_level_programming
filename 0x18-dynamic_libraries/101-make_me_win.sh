#!/bin/bash
wget -P /tmp/ /tmp https://github.com/SamuelAmihere/alx-low_level_programming/tree/master/0x18-dynamic_libraries/libgenerator.so
export LD_PRELOAD=/tmp/libgenerator.so
