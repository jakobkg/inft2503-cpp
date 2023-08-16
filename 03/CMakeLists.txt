cmake_minimum_required(VERSION 3.5)

project(assignment_03)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

# Oppgave 1 settes opp som et bibliotek, ingen main
add_library(circle circle.cpp)

# Oppgave 2 bruker biblioteket fra oppgave 1
add_executable(task_2 task_2.cpp)
target_link_libraries(task_2 circle)

# Oppgave 3 er et bibliotek og et program som bruker biblioteket
add_library(commodity commodity.cpp)

add_executable(task_3 task_3.cpp)
target_link_libraries(task_3 commodity)

# Oppgave 4
add_executable(task_4 task_4.cpp)