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

# Include any dependencies generated for this target.
include _deps/imgui_bundle-build/CMakeFiles/imgui_bundle.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/imgui_bundle-build/CMakeFiles/imgui_bundle.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/imgui_bundle-build/CMakeFiles/imgui_bundle.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/imgui_bundle-build/CMakeFiles/imgui_bundle.dir/flags.make

_deps/imgui_bundle-build/CMakeFiles/imgui_bundle.dir/src/imgui_bundle/imgui_bundle.cpp.o: _deps/imgui_bundle-build/CMakeFiles/imgui_bundle.dir/flags.make
_deps/imgui_bundle-build/CMakeFiles/imgui_bundle.dir/src/imgui_bundle/imgui_bundle.cpp.o: _deps/imgui_bundle-build/CMakeFiles/imgui_bundle.dir/includes_CXX.rsp
_deps/imgui_bundle-build/CMakeFiles/imgui_bundle.dir/src/imgui_bundle/imgui_bundle.cpp.o: _deps/imgui_bundle-src/src/imgui_bundle/imgui_bundle.cpp
_deps/imgui_bundle-build/CMakeFiles/imgui_bundle.dir/src/imgui_bundle/imgui_bundle.cpp.o: _deps/imgui_bundle-build/CMakeFiles/imgui_bundle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clement/Desktop/vielsprachig/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/imgui_bundle-build/CMakeFiles/imgui_bundle.dir/src/imgui_bundle/imgui_bundle.cpp.o"
	cd /home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-build && /usr/lib/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/imgui_bundle-build/CMakeFiles/imgui_bundle.dir/src/imgui_bundle/imgui_bundle.cpp.o -MF CMakeFiles/imgui_bundle.dir/src/imgui_bundle/imgui_bundle.cpp.o.d -o CMakeFiles/imgui_bundle.dir/src/imgui_bundle/imgui_bundle.cpp.o -c /home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-src/src/imgui_bundle/imgui_bundle.cpp

_deps/imgui_bundle-build/CMakeFiles/imgui_bundle.dir/src/imgui_bundle/imgui_bundle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imgui_bundle.dir/src/imgui_bundle/imgui_bundle.cpp.i"
	cd /home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-build && /usr/lib/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-src/src/imgui_bundle/imgui_bundle.cpp > CMakeFiles/imgui_bundle.dir/src/imgui_bundle/imgui_bundle.cpp.i

_deps/imgui_bundle-build/CMakeFiles/imgui_bundle.dir/src/imgui_bundle/imgui_bundle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imgui_bundle.dir/src/imgui_bundle/imgui_bundle.cpp.s"
	cd /home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-build && /usr/lib/emscripten/em++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-src/src/imgui_bundle/imgui_bundle.cpp -o CMakeFiles/imgui_bundle.dir/src/imgui_bundle/imgui_bundle.cpp.s

# Object files for target imgui_bundle
imgui_bundle_OBJECTS = \
"CMakeFiles/imgui_bundle.dir/src/imgui_bundle/imgui_bundle.cpp.o"

# External object files for target imgui_bundle
imgui_bundle_EXTERNAL_OBJECTS =

_deps/imgui_bundle-build/libimgui_bundle.a: _deps/imgui_bundle-build/CMakeFiles/imgui_bundle.dir/src/imgui_bundle/imgui_bundle.cpp.o
_deps/imgui_bundle-build/libimgui_bundle.a: _deps/imgui_bundle-build/CMakeFiles/imgui_bundle.dir/build.make
_deps/imgui_bundle-build/libimgui_bundle.a: _deps/imgui_bundle-build/CMakeFiles/imgui_bundle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/clement/Desktop/vielsprachig/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libimgui_bundle.a"
	cd /home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-build && $(CMAKE_COMMAND) -P CMakeFiles/imgui_bundle.dir/cmake_clean_target.cmake
	cd /home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-build && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/imgui_bundle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/imgui_bundle-build/CMakeFiles/imgui_bundle.dir/build: _deps/imgui_bundle-build/libimgui_bundle.a
.PHONY : _deps/imgui_bundle-build/CMakeFiles/imgui_bundle.dir/build

_deps/imgui_bundle-build/CMakeFiles/imgui_bundle.dir/clean:
	cd /home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-build && $(CMAKE_COMMAND) -P CMakeFiles/imgui_bundle.dir/cmake_clean.cmake
.PHONY : _deps/imgui_bundle-build/CMakeFiles/imgui_bundle.dir/clean

_deps/imgui_bundle-build/CMakeFiles/imgui_bundle.dir/depend:
	cd /home/clement/Desktop/vielsprachig/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/clement/Desktop/vielsprachig /home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-src /home/clement/Desktop/vielsprachig/build /home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-build /home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-build/CMakeFiles/imgui_bundle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/imgui_bundle-build/CMakeFiles/imgui_bundle.dir/depend

