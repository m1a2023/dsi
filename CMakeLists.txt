cmake_minimum_required(VERSION 3.10)

# Project name and version
project(dsi VERSION 1.0.2)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define source files for the LinkedList and Stack library
set(LIBRARY_SOURCES
    src/source/LinkedList.cpp
    src/source/PostfixNotationReader.cpp
    src/source/PostfixNotationTranslator.cpp
)

# Include directories for headers
include_directories(src/headers)

# Find spdlog library
find_package(spdlog REQUIRED)

# Set platform-specific compiler flags
if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DWINDOWS")
    set(OUTPUT_DIR "${CMAKE_SOURCE_DIR}/bin/windows")
elseif (UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DLINUX")
    set(OUTPUT_DIR "${CMAKE_SOURCE_DIR}/bin/linux")
endif()

# Set common output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR}/bin)

# Create shared libraries
add_library(lib_shared SHARED ${LIBRARY_SOURCES})

# Create the executable
add_executable(dsi src/main.cpp)

# Link the executable with the shared libraries
target_link_libraries(dsi
    lib_shared
    spdlog::spdlog
)
