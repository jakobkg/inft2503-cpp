cmake_minimum_required(VERSION 3.5)

project(assignment_01)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

# Alle deloppgaver er hver sin programfil
add_executable(task_a task_a.cpp)
add_executable(task_b task_b.cpp)