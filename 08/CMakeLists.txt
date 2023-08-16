cmake_minimum_required(VERSION 3.5)

project(assignment_05)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

# Oppgave 1, bare et lite program
add_executable(task_1 task_1.cpp)

# Opgpave 2, klasse og klient
add_library(pair pair.cpp)
add_executable(task_2 task_2.cpp)
target_link_libraries(task_2 pair)