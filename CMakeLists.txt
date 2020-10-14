cmake_minimum_required(VERSION 3.17)
project(triangles)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE DEBUG)

find_package(OpenGL REQUIRED COMPONENTS OpenGL)
find_package(GLUT REQUIRED)

add_executable(triangles main.cpp)

add_dependencies(triangles OpenGL::OpenGL)
include_directories(${GLUT_INCLUDE_DIRS})

target_link_libraries(triangles OpenGL::OpenGL ${GLUT_LIBRARY})
target_link_libraries(triangles GLU)
target_link_libraries(triangles GL)