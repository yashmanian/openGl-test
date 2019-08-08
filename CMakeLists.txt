project(openGlTest)
cmake_minimum_required(VERSION 3.5)

#find_package(OpenGL)
#find_package(GLUT)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
set(WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
add_definitions(-DNOMINMAX)

# Added for force C++11 build options
set(CMAKE_CXX_STANDARD 11) # C++11...
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF) #...without compiler extensions like gnu++11

file(MAKE_DIRECTORY "bin")
file(MAKE_DIRECTORY "lib")

set(LINK_LIBRARIES GLEW glut GLU GL)

add_executable(glTest src/test1.cpp)
target_link_libraries(glTest ${LINK_LIBRARIES})