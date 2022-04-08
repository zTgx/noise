#Author : zTgx
#Date   : 2022-04-08
#Desc   : noise example

cmake_minimum_required (VERSION 3.16)

if (POLICY CMP0074)
  cmake_policy(SET CMP0074 NEW)
endif ()

set(PROJECTNAME hinoise)
project(${PROJECTNAME})

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER "/usr/bin/g++-11")

# config g++-11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
set(CMAKE_CXX_FLAGSD "${CMAKE_CXX_FLAGS} -O0 -Wall -g -ggdb")

AUX_SOURCE_DIRECTORY(./ DIR_MAIN_SRCS)
ADD_EXECUTABLE(${PROJECTNAME} ${DIR_MAIN_SRCS})

# header location
INCLUDE_DIRECTORIES("../src")
# target_include_directories(${PROJECTNAME} PUBLIC "../../my_build")

set(NOISE_PATH "${PROJECT_SOURCE_DIR}/../my_build/libnoise.a")
# message (${NOISE_PATH})
# message ("binary path: " ${CMAKE_BINARY_DIR})
target_link_libraries(${PROJECTNAME} ${NOISE_PATH})
target_link_libraries(${PROJECTNAME} -pthread)
