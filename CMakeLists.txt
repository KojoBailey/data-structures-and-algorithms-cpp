cmake_minimum_required(VERSION 3.28)
project(algos_and_data_structs DESCRIPTION "Implementation of some data structures and algorithms.")

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc -static-libstdc++")

file(GLOB SOURCES
	src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
