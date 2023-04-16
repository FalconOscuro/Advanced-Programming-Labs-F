# Individual task build
project(01-Templates LANGUAGES CXX)
cmake_minimum_required(VERSION 3.16)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # Export compile commands for cppcheck

add_executable(${PROJECT_NAME} Main.cpp)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    COMPILE_OPTIONS "-Werror;-Wall;-Wextra" # Enable compiler warnings
)

configure_file(Grid1.txt ${CMAKE_CURRENT_BINARY_DIR}/Grid1.txt COPYONLY)