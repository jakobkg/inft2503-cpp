cmake_minimum_required(VERSION 3.5)

project(assignment_07)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

# Oppgave 1 er et brøk-bibliotek, og et program som bruker biblioteket
add_library(fraction fraction.cpp)
add_executable(task_1 task_1.cpp)
target_link_libraries(task_1 fraction)

# Oppgave 2 er et sett-bibliotek, og et program som bruker biblioteket
add_library(set set.cpp)
add_executable(task_2 task_2.cpp)
target_link_libraries(task_2 set)
