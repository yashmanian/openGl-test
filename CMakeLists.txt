project(GLUT)
cmake_minimum_required(VERSION 2.8)

find_package(OpenGL)
find_package(GLUT)

add_executable(glut src/test1.cpp)
target_link_libraries(glut ${OPENGL_gl_LIBRARY} ${GLUT_LIBRARIES} GLU)