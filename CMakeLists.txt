cmake_minimum_required(VERSION 3.14)
project(hf_sim)

set(CMAKE_BUILD_TYPE Debug)

 
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
#list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})
 
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-O2 -pedantic -W -Wall -Wshadow -fPIC")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
 
#include PYTHIA 8 and ROOT
find_package(ROOT REQUIRED COMPONENTS Tree)
include(${ROOT_USE_FILE})

find_package(Pythia8 REQUIRED)
include_directories("${PYTHIA8_INCLUDE_DIR}")

add_subdirectory(analysis)

add_executable(hsim main.cc)
target_link_libraries(hsim "${PYTHIA8_LIBRARIES}")
target_link_libraries(hsim "${ROOT_LIBRARIES}")

target_link_libraries(hsim analysis)
