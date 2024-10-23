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
CMAKE_SOURCE_DIR = /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/linked_list

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/linked_list/build

# Include any dependencies generated for this target.
include CMakeFiles/dsi_app.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/dsi_app.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/dsi_app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dsi_app.dir/flags.make

CMakeFiles/dsi_app.dir/src/main.cpp.o: CMakeFiles/dsi_app.dir/flags.make
CMakeFiles/dsi_app.dir/src/main.cpp.o: /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/linked_list/src/main.cpp
CMakeFiles/dsi_app.dir/src/main.cpp.o: CMakeFiles/dsi_app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/linked_list/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dsi_app.dir/src/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/dsi_app.dir/src/main.cpp.o -MF CMakeFiles/dsi_app.dir/src/main.cpp.o.d -o CMakeFiles/dsi_app.dir/src/main.cpp.o -c /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/linked_list/src/main.cpp

CMakeFiles/dsi_app.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/dsi_app.dir/src/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/linked_list/src/main.cpp > CMakeFiles/dsi_app.dir/src/main.cpp.i

CMakeFiles/dsi_app.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/dsi_app.dir/src/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/linked_list/src/main.cpp -o CMakeFiles/dsi_app.dir/src/main.cpp.s

# Object files for target dsi_app
dsi_app_OBJECTS = \
"CMakeFiles/dsi_app.dir/src/main.cpp.o"

# External object files for target dsi_app
dsi_app_EXTERNAL_OBJECTS =

/home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/linked_list/bin/lib/dsi_app: CMakeFiles/dsi_app.dir/src/main.cpp.o
/home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/linked_list/bin/lib/dsi_app: CMakeFiles/dsi_app.dir/build.make
/home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/linked_list/bin/lib/dsi_app: liblinkedlist_shared.so
/home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/linked_list/bin/lib/dsi_app: CMakeFiles/dsi_app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/linked_list/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/linked_list/bin/lib/dsi_app"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dsi_app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dsi_app.dir/build: /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/linked_list/bin/lib/dsi_app
.PHONY : CMakeFiles/dsi_app.dir/build

CMakeFiles/dsi_app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dsi_app.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dsi_app.dir/clean

CMakeFiles/dsi_app.dir/depend:
	cd /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/linked_list/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/linked_list /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/linked_list /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/linked_list/build /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/linked_list/build /home/qpwesuf/dev/algorithms/dynamical-stuctures-implementation/linked_list/build/CMakeFiles/dsi_app.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/dsi_app.dir/depend

