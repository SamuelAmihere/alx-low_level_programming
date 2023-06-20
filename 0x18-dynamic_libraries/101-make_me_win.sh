#!/bin/bash
wget -P https://github.com/SamuelAmihere/alx-low_level_programming/blob/master/0x18-dynamic_libraries/generator.o
gcc -fPIC -shared *.o -0 libgenerator.o
