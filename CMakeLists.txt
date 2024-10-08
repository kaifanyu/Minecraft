cmake_minimum_required(VERSION 3.5.0)
project(minecraft)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable (without WIN32 to indicate console app)
file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(minecraft ${SRC_FILES})

# Include GLAD headers
include_directories(${CMAKE_SOURCE_DIR}/lib/glad/include)

# Include GLFW headers
include_directories(${CMAKE_SOURCE_DIR}/lib/glfw/include)

# Include CGLM headers
include_directories(${CMAKE_SOURCE_DIR}/lib/cglm/include)

# Include stb.h
include_directories(${CMAKE_SOURCE_DIR}/lib/stb)

# Include stb.h
include_directories(${CMAKE_SOURCE_DIR}/lib/libfreetype2/freetype2/include)

# Link GLAD source file (compile directly)
add_library(glad STATIC lib/glad/src/glad.c)

# Specify the exact path for GLFW static library (ensure it's 64-bit if you're building 64-bit)
set(GLFW_LIB ${CMAKE_SOURCE_DIR}/lib/glfw/lib/glfw3.lib)  # For 64-bit Visual Studio build

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
file(COPY ${CMAKE_SOURCE_DIR}/assets/images DESTINATION ${CMAKE_BINARY_DIR}/assets)
file(COPY ${CMAKE_SOURCE_DIR}/assets/textures DESTINATION ${CMAKE_BINARY_DIR}/assets)

add_definitions(-DASSETS_DIR=\"${CMAKE_BINARY_DIR}/assets/\")