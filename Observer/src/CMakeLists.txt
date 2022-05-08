cmake_minimum_required(VERSION 3.10)

# set the project name
project(Observer)

# add the executable
add_executable(Observer ObserversDriver.cpp IObserver.cpp) 

# add the include directory
target_include_directories(Observer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}" )
