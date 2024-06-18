cmake_minimum_required(VERSION 3.28)
project(PhysicsDemo)

set(CMAKE_CXX_STANDARD 23)
set(EXT_LIB_PATH ${CMAKE_SOURCE_DIR}/ext)

file(COPY resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(${EXT_LIB_PATH}/FrogEngine)

add_executable(
        PhysicsDemo
        
        src/main.cpp
        src/MovablePlatform.cpp
        src/PhysicsDemo.cpp
        src/RopeSegment.cpp
        src/Rope.cpp
        src/Zombie.cpp
)

target_link_libraries(PhysicsDemo
        FrogEngine
)