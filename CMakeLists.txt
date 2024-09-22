cmake_minimum_required(VERSION 3.30.0)
project(minecraft)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(minecraft src/main.cpp)

# Include GLAD headers
include_directories(${CMAKE_SOURCE_DIR}/lib/glad/include)

# Include GLFW headers
include_directories(${CMAKE_SOURCE_DIR}/lib/glfw/include)

# Link GLAD source file (compile directly)
add_library(glad STATIC lib/glad/src/glad.c)

# Specify the exact path for GLFW static library
set(GLFW_LIB ${CMAKE_SOURCE_DIR}/lib/glfw/lib/libglfw3.a)

# Add OpenGL (for cross-platform OpenGL support)
find_package(OpenGL REQUIRED)

# Link libraries to the executable
target_link_libraries(minecraft glad ${GLFW_LIB} ${OPENGL_gl_LIBRARY})
