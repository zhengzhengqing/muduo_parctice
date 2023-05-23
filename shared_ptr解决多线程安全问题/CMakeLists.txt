cmake_minimum_required(VERSION 3.0.2)
project(manager)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")


add_executable(test
 main.cc
 observer.cc
 observable.cc
)
#add_dependencies(server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin#_EXPORTED_TARGETS})
target_link_libraries(test
 -lpthread
)