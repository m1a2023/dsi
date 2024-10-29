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
    src/headers/Queue.h
    src/headers/IDataStructure.h
    src/headers/Node.h
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
add_library(linkedlist_static STATIC ${LIBRARY_SOURCES} "src/headers/LinkedList.h")
add_library(stack_static STATIC ${LIBRARY_SOURCES} "src/headers/Stack.h")
add_library(queue_static STATIC ${LIBRARY_SOURCES} "src/headers/Queue.h")
add_library(time_measurer_static STATIC ${LIBRARY_SOURCES} "src/headers/TimeMeasurer.h")
add_library(file_reader_static STATIC ${LIBRARY_SOURCES} "src/headers/FileReader.h")

# Create static libraries
add_library(linkedlist_shared SHARED ${LIBRARY_SOURCES} "src/headers/LinkedList.h")
add_library(stack_shared SHARED ${LIBRARY_SOURCES} "src/headers/Stack.h")
add_library(queue_shared SHARED ${LIBRARY_SOURCES} "src/headers/Queue.h")
add_library(time_measurer_shared SHARED ${LIBRARY_SOURCES} "src/headers/TimeMeasurer.h")
add_library(file_reader_shared SHARED ${LIBRARY_SOURCES} "src/headers/FileReader.h")

# Set output directories for the libraries
set_target_properties(linkedlist_static PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)
set_target_properties(stack_static PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)
set_target_properties(queue_static PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)
set_target_properties(time_measurer_static PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)
set_target_properties(file_reader_static PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)

set_target_properties(linkedlist_shared PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)
set_target_properties(stack_shared PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)
set_target_properties(queue_shared PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)
set_target_properties(time_measurer_shared PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)
set_target_properties(file_reader_shared PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)

# Set the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR}/bin)

# Create the executable
add_executable(dsi src/main.cpp)

# Link the executable with the shared library
target_link_libraries(
    dsi
    linkedlist_shared 
    stack_shared
    queue_shared 
    time_measurer_shared
    file_reader_shared
)
