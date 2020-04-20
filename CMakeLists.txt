cmake_minimum_required(VERSION 3.14)
project(HeavySim)

set(CMAKE_BUILD_TYPE Debug)


list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O2 -pedantic -W -Wall -Wshadow -fPIC")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#include BOOST
find_package(Boost 1.72 REQUIRED)
 
# Include ROOT
find_package(ROOT REQUIRED COMPONENTS Tree)
include(${ROOT_USE_FILE})

#include PYTHIA
find_package(Pythia8 REQUIRED)
include_directories("${PYTHIA8_INCLUDE_DIR}")



add_subdirectory(container)
add_subdirectory(analysis)
add_subdirectory(tree_analysis)

add_library(pythia_utils SHARED pythia_particle_utils.cpp pythia_event_utils.cpp)
target_link_libraries(pythia_utils "${PYTHIA8_LIBRARIES}" container)

add_executable(generate generate.cc)
target_link_libraries(generate "${PYTHIA8_LIBRARIES}" "${ROOT_LIBRARIES}" container analysis pythia_utils)

add_executable(analyze analyse.cpp)
target_link_libraries(analyze container tree_analysis)

