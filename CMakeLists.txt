cmake_minimum_required(VERSION 3.28)
project(PhysicsDemo)

set(CMAKE_CXX_STANDARD 23)
set(EXT_LIB_PATH ${CMAKE_SOURCE_DIR}/ext)

add_executable(
        PhysicsDemo
        
        src/main.cpp
)