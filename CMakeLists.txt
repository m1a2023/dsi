cmake_minimum_required(VERSION 3.10)

# Project name and version
project(dsi VERSION 1.0.2)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define source files for the LinkedList library
set(LIBRARY_SOURCES
    src/source/LinkedList.cpp
    #src/source/Stack.cpp
    # Add other source files if needed
)

# Define header files for the LinkedList library (optional)
set(LIBRARY_HEADERS
    src/headers/LinkedList.h
    src/headers/Stack.h
    # Add other header files if needed
)

# Create a static library
add_library(linkedlist_static  STATIC ${LIBRARY_SOURCES})
add_library(stack_static       STATIC ${LIBRARY_SOURCES})

# Create a shared library
add_library(linkedlist_shared   SHARED ${LIBRARY_SOURCES})
add_library(stack_shared        SHARED ${LIBRARY_SOURCES})

# Set the output directories for the libraries
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin) # For static libraries (.a)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin) # For shared libraries (.so)

# Set the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/lib) # For executable

# Create the executable
add_executable(dsi_app src/main.cpp)

# Link the executable with the shared library
target_link_libraries(dsi_app linkedlist_shared)
