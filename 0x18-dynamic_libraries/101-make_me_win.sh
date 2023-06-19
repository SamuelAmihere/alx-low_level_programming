#!/bin/bash
wget -P /tmp https://github.com/SamuelAmihere/alx-low_level_programming/blob/master/0x18-dynamic_libraries/libgenerator.so
export LD_PRELOAD=/tmp/libgenerator.so
