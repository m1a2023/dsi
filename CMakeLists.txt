cmake_minimum_required(VERSION 3.10)

# Project name and version
project(dsi VERSION 1.0.2)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define source files for the LinkedList and Stack library
set(LIBRARY_SOURCES
    src/source/LinkedList.cpp
    # Add other source files if needed
)

# Define header files for the libraries (optional)
set(LIBRARY_HEADERS
    src/headers/LinkedList.h
    src/headers/Stack.h
)

# Set platform-specific compiler flags
if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DWINDOWS")
    set(OUTPUT_DIR "${CMAKE_SOURCE_DIR}/bin/windows")
elseif (UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DLINUX")
    set(OUTPUT_DIR "${CMAKE_SOURCE_DIR}/bin/linux")
endif()

# Create static libraries
add_library(linkedlist_static STATIC ${LIBRARY_SOURCES} "src/headers/Queue.h")
add_library(stack_static STATIC ${LIBRARY_SOURCES} "src/headers/Queue.h")

# Create shared libraries
add_library(linkedlist_shared SHARED ${LIBRARY_SOURCES} "src/headers/Queue.h")
add_library(stack_shared SHARED ${LIBRARY_SOURCES} "src/headers/Queue.h")

# Set output directories for the libraries
set_target_properties(linkedlist_static PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)
set_target_properties(stack_static PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)
set_target_properties(linkedlist_shared PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)
set_target_properties(stack_shared PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)

# Set the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR}/bin)

# Create the executable
add_executable(dsi_app src/main.cpp)

# Link the executable with the shared library
target_link_libraries(dsi_app)
