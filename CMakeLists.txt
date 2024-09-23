cmake_minimum_required(VERSION 3.3.0)
project(minecraft)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable (with WIN32 to prevent console window on Windows)
# add_executable(minecraft src/main.cpp src/gfx/shader.cpp)
add_executable(minecraft WIN32 src/main.cpp src/gfx/shader.cpp)

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

# Static link the C++ standard library, GCC runtime, and pthread (for MinGW builds)
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_libraries(minecraft "-static-libstdc++" "-static-libgcc" "-static")
endif()

# Copy shader files to the build directory
file(COPY ${CMAKE_SOURCE_DIR}/assets/shaders DESTINATION ${CMAKE_BINARY_DIR}/assets)
