cmake_minimum_required(VERSION 3.0.2)
project(exception)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
add_executable(exception exception.cc main.cc)
target_link_libraries(exception)
