set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)

set(CMAKE_FIND_ROOT_PATH /home/wjxh/linux/tool/gcc-linaro-4.9.4-2017.01-x86_64_arm-linux-gnueabihf)


set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")  # For C code
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")  # For C++ code