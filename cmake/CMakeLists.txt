cmake_minimum_required(VERSION 3.21.2)
project("Hello World")
# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
# Set the CXXFLAGS
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -pedantic")
add_subdirectory(libhello)

add_executable(hello main.cc)
target_link_libraries(hello PRIVATE libhello)
