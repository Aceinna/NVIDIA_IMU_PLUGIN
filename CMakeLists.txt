#Copyright (c) 2021, ACEINNA.  All rights reserved.

#Set minimum cmake version
cmake_minimum_required(VERSION 3.5)

set(CMAKE_VERBOSE_MAKEFILE ON)

#Set project name
project(aceinna_openimu_plugin C CXX)

#Set compiler settings
set(CMAKE_CXX_FLAGS "-std=c++11")
if(ARM)
    set(CMAKE_CXX_COMPILER aarch64-linux-gnu-g++)
    message(STATUS "================")
    message(STATUS "Building for ARM")
    message(STATUS "================")
endif()

#Set paths for dependencies
if(ARM)
    set(CUDA_INCLUDE_DIR "${CUDA_PATH}/targets/aarch64-linux/include")
    set(Driveworks_INCLUDE_DIR "${DW_PATH}/targets/aarch64-Linux/include")
else()
    set(CUDA_INCLUDE_DIR "/usr/local/cuda-10.2/targets/x86_64-linux/include")
    set(Driveworks_INCLUDE_DIR "${DW_PATH}/targets/x86_64-Linux/include")
endif()

set(SAMPLE_PLUGINS_COMMON_DIR "${DW_PATH}/include")

#Include dependencies

include_directories(include)
include_directories(
    ${CUDA_INCLUDE_DIR}
    ${Driveworks_INCLUDE_DIR}
    ${DW_PATH}/samples/src/sensors/plugins/common
)
include_directories(${SAMPLE_PLUGINS_COMMON_DIR})
message("${SAMPLE_PLUGINS_COMMON_DIR}")
message("${CUDA_INCLUDE_DIR}")
#-------------------------------------------------------------------------------
# Project files
#-------------------------------------------------------------------------------
set(PUBLIC_DOCS
    README.md
)

set(SOURCES
    src/main.cpp
    src/openimu300_plugin.cpp
    include/imu.h
    include/openimu300_plugin.h
    )

set(LIBRARIES
    ${Driveworks_LIBRARIES}
)

#-------------------------------------------------------------------------------
# Final target
#-------------------------------------------------------------------------------
add_library(${PROJECT_NAME} SHARED ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBRARIES})
set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "Samples")


#Define DEBUG DEFINE FLAGS
set(CMAKE_CXX_FLAGS_DEBUG "-DNDEBUG=0 -O0 -g3")


#Define RELEASE DEFINE FLAGS
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG=1 -O3 -g1")

message(STATUS "CMAKE_CXX_FLAGS_DEBUG is " ${CMAKE_CXX_FLAGS_DEBUG})
message(STATUS "CMAKE_CXX_FLAGS_RELEASE is " ${CMAKE_CXX_FLAGS_RELEASE})

#Echo out compiler path
message(STATUS "C++ Compiler is: ${CMAKE_CXX_COMPILER}")
# ------------------------------------------------------------------------------
# Install target
# ------------------------------------------------------------------------------
#get_property(TARGET_PACKAGE GLOBAL PROPERTY TARGET_PACKAGE)
#install(TARGETS ${PROJECT_NAME}
#    COMPONENT dw-samples-${TARGET_PACKAGE} # targeted package (dw / dav / ..)
#    DESTINATION ${SDK_SAMPLE_DESTINATION}
#)

#install(TARGETS ${PROJECT_NAME}
#    COMPONENT dw-tests
#    DESTINATION ${SDK_SAMPLE_DESTINATION}
#)
