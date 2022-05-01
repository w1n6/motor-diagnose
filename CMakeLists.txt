cmake_minimum_required(VERSION 3.22)
project(motor_diagnose)


set(CMAKE_CXX_STANDARD 20)

set(SYSROOT_PATH /)
set(CMAKE_SYSROOT ${SYSROOT_PATH})
set(CMAKE_FIND_ROOT_PATH "${SYSROOT_PATH}" "${CMAKE_PREFIX_PATH}" "${TOOLCHAIN_PATH}")
set(INC_DIR /usr/include/)

include_directories(${INC_DIR})
add_executable(motor_diagnose main.cpp)
