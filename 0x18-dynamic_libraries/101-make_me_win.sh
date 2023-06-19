#!/bin/bash
wget -P /tmp https://github.com/SamuelAmihere/alx-low_level_programming/tree/master/0x18-dynamic_libraries/generator.so
export LD_PRELOAD=/tmp/generator.so
