cmake_minimum_required(VERSION 3.5)

project(assignment_06)

INCLUDE(FindPkgConfig)

# Øvingen krever Boost-biblioteket installert
find_package(Boost 1.78 REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

# Oppgave 1 er mer sjakk
add_executable(chess chess.cpp)

# Oppgave 2 er en liten webserver som bruker Boost ASIO-biblioteket
add_executable(server server.cpp)
target_link_libraries(server ${Boost_LIBRARIES})
