# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/dsi/dsi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/dsi/dsi/build

# Include any dependencies generated for this target.
include CMakeFiles/linkedlist_shared.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/linkedlist_shared.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/linkedlist_shared.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/linkedlist_shared.dir/flags.make

CMakeFiles/linkedlist_shared.dir/src/source/LinkedList.cpp.o: CMakeFiles/linkedlist_shared.dir/flags.make
CMakeFiles/linkedlist_shared.dir/src/source/LinkedList.cpp.o: /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/dsi/dsi/src/source/LinkedList.cpp
CMakeFiles/linkedlist_shared.dir/src/source/LinkedList.cpp.o: CMakeFiles/linkedlist_shared.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/dsi/dsi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/linkedlist_shared.dir/src/source/LinkedList.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/linkedlist_shared.dir/src/source/LinkedList.cpp.o -MF CMakeFiles/linkedlist_shared.dir/src/source/LinkedList.cpp.o.d -o CMakeFiles/linkedlist_shared.dir/src/source/LinkedList.cpp.o -c /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/dsi/dsi/src/source/LinkedList.cpp

CMakeFiles/linkedlist_shared.dir/src/source/LinkedList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/linkedlist_shared.dir/src/source/LinkedList.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/dsi/dsi/src/source/LinkedList.cpp > CMakeFiles/linkedlist_shared.dir/src/source/LinkedList.cpp.i

CMakeFiles/linkedlist_shared.dir/src/source/LinkedList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/linkedlist_shared.dir/src/source/LinkedList.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/dsi/dsi/src/source/LinkedList.cpp -o CMakeFiles/linkedlist_shared.dir/src/source/LinkedList.cpp.s

CMakeFiles/linkedlist_shared.dir/src/source/PostfixNotationReader.cpp.o: CMakeFiles/linkedlist_shared.dir/flags.make
CMakeFiles/linkedlist_shared.dir/src/source/PostfixNotationReader.cpp.o: /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/dsi/dsi/src/source/PostfixNotationReader.cpp
CMakeFiles/linkedlist_shared.dir/src/source/PostfixNotationReader.cpp.o: CMakeFiles/linkedlist_shared.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/dsi/dsi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/linkedlist_shared.dir/src/source/PostfixNotationReader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/linkedlist_shared.dir/src/source/PostfixNotationReader.cpp.o -MF CMakeFiles/linkedlist_shared.dir/src/source/PostfixNotationReader.cpp.o.d -o CMakeFiles/linkedlist_shared.dir/src/source/PostfixNotationReader.cpp.o -c /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/dsi/dsi/src/source/PostfixNotationReader.cpp

CMakeFiles/linkedlist_shared.dir/src/source/PostfixNotationReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/linkedlist_shared.dir/src/source/PostfixNotationReader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/dsi/dsi/src/source/PostfixNotationReader.cpp > CMakeFiles/linkedlist_shared.dir/src/source/PostfixNotationReader.cpp.i

CMakeFiles/linkedlist_shared.dir/src/source/PostfixNotationReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/linkedlist_shared.dir/src/source/PostfixNotationReader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/dsi/dsi/src/source/PostfixNotationReader.cpp -o CMakeFiles/linkedlist_shared.dir/src/source/PostfixNotationReader.cpp.s

# Object files for target linkedlist_shared
linkedlist_shared_OBJECTS = \
"CMakeFiles/linkedlist_shared.dir/src/source/LinkedList.cpp.o" \
"CMakeFiles/linkedlist_shared.dir/src/source/PostfixNotationReader.cpp.o"

# External object files for target linkedlist_shared
linkedlist_shared_EXTERNAL_OBJECTS =

/home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/dsi/dsi/bin/linux/lib/liblinkedlist_shared.so: CMakeFiles/linkedlist_shared.dir/src/source/LinkedList.cpp.o
/home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/dsi/dsi/bin/linux/lib/liblinkedlist_shared.so: CMakeFiles/linkedlist_shared.dir/src/source/PostfixNotationReader.cpp.o
/home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/dsi/dsi/bin/linux/lib/liblinkedlist_shared.so: CMakeFiles/linkedlist_shared.dir/build.make
/home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/dsi/dsi/bin/linux/lib/liblinkedlist_shared.so: CMakeFiles/linkedlist_shared.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/dsi/dsi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/dsi/dsi/bin/linux/lib/liblinkedlist_shared.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/linkedlist_shared.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/linkedlist_shared.dir/build: /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/dsi/dsi/bin/linux/lib/liblinkedlist_shared.so
.PHONY : CMakeFiles/linkedlist_shared.dir/build

CMakeFiles/linkedlist_shared.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/linkedlist_shared.dir/cmake_clean.cmake
.PHONY : CMakeFiles/linkedlist_shared.dir/clean

CMakeFiles/linkedlist_shared.dir/depend:
	cd /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/dsi/dsi/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/dsi/dsi /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/dsi/dsi /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/dsi/dsi/build /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/dsi/dsi/build /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/dsi/dsi/build/CMakeFiles/linkedlist_shared.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/linkedlist_shared.dir/depend

