cmake_minimum_required(VERSION 3.5)

project(assignment_04)

INCLUDE(FindPkgConfig)

# Øvingen krever GTKMM 3.0
pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

# Oppgave 1
add_executable(task_1 task_1.cpp)

# Oppgave 2 linker til GTKMM
add_executable(task_2 task_2.cpp)
target_link_libraries(task_2 ${GTKMM_LIBRARIES})