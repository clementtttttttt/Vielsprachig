# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_SOURCE_DIR = /home/clement/Desktop/vielsprachig

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/clement/Desktop/vielsprachig/build

# Utility rule file for ExperimentalTest.

# Include any custom commands dependencies for this target.
include libarchive/CMakeFiles/ExperimentalTest.dir/compiler_depend.make

# Include the progress variables for this target.
include libarchive/CMakeFiles/ExperimentalTest.dir/progress.make

libarchive/CMakeFiles/ExperimentalTest:
	cd /home/clement/Desktop/vielsprachig/build/libarchive && /usr/bin/ctest -D ExperimentalTest

ExperimentalTest: libarchive/CMakeFiles/ExperimentalTest
ExperimentalTest: libarchive/CMakeFiles/ExperimentalTest.dir/build.make
.PHONY : ExperimentalTest

# Rule to build all files generated by this target.
libarchive/CMakeFiles/ExperimentalTest.dir/build: ExperimentalTest
.PHONY : libarchive/CMakeFiles/ExperimentalTest.dir/build

libarchive/CMakeFiles/ExperimentalTest.dir/clean:
	cd /home/clement/Desktop/vielsprachig/build/libarchive && $(CMAKE_COMMAND) -P CMakeFiles/ExperimentalTest.dir/cmake_clean.cmake
.PHONY : libarchive/CMakeFiles/ExperimentalTest.dir/clean

libarchive/CMakeFiles/ExperimentalTest.dir/depend:
	cd /home/clement/Desktop/vielsprachig/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/clement/Desktop/vielsprachig /home/clement/Desktop/vielsprachig/libarchive /home/clement/Desktop/vielsprachig/build /home/clement/Desktop/vielsprachig/build/libarchive /home/clement/Desktop/vielsprachig/build/libarchive/CMakeFiles/ExperimentalTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libarchive/CMakeFiles/ExperimentalTest.dir/depend

