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
    # Add other source files if needed
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
add_library(linkedlist_shared SHARED ${LIBRARY_SOURCES})
add_library(stack_shared SHARED ${LIBRARY_SOURCES})
add_library(queue_shared SHARED ${LIBRARY_SOURCES})
add_library(time_measurer_shared SHARED ${LIBRARY_SOURCES})
add_library(file_reader_shared SHARED ${LIBRARY_SOURCES})
add_library(postfix_notation_reader_shared SHARED ${LIBRARY_SOURCES})
add_library(postfix_notation_translator_shared SHARED ${LIBRARY_SOURCES})

# Create the executable
add_executable(dsi src/main.cpp)

# Link the executable with the shared libraries
target_link_libraries(dsi
    linkedlist_shared 
    stack_shared
    queue_shared 
    time_measurer_shared
    file_reader_shared
    postfix_notation_reader_shared
    postfix_notation_translator_shared
    spdlog::spdlog
)
