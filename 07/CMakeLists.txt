cmake_minimum_required(VERSION 3.5)

project(assignment_06)

INCLUDE(FindPkgConfig)

find_package(Boost 1.78 REQUIRED)

include_directories(${Boost_INCLUDE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

# Oppgave 1 er mer fraction
add_library(fraction fraction.cpp)
add_executable(task_1 task_1.cpp)
target_link_libraries(task_1 fraction)

# Oppgave 2 er et sett
add_library(set set.cpp)
add_executable(task_2 task_2.cpp)
target_link_libraries(task_2 set)
