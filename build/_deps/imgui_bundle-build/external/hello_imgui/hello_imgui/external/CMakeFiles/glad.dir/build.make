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
include _deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external/CMakeFiles/glad.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external/CMakeFiles/glad.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external/CMakeFiles/glad.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external/CMakeFiles/glad.dir/flags.make

_deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external/CMakeFiles/glad.dir/OpenGL_Loaders/glad/src/glad.c.o: _deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external/CMakeFiles/glad.dir/flags.make
_deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external/CMakeFiles/glad.dir/OpenGL_Loaders/glad/src/glad.c.o: _deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external/CMakeFiles/glad.dir/includes_C.rsp
_deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external/CMakeFiles/glad.dir/OpenGL_Loaders/glad/src/glad.c.o: _deps/imgui_bundle-src/external/hello_imgui/hello_imgui/external/OpenGL_Loaders/glad/src/glad.c
_deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external/CMakeFiles/glad.dir/OpenGL_Loaders/glad/src/glad.c.o: _deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external/CMakeFiles/glad.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clement/Desktop/vielsprachig/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object _deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external/CMakeFiles/glad.dir/OpenGL_Loaders/glad/src/glad.c.o"
	cd /home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT _deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external/CMakeFiles/glad.dir/OpenGL_Loaders/glad/src/glad.c.o -MF CMakeFiles/glad.dir/OpenGL_Loaders/glad/src/glad.c.o.d -o CMakeFiles/glad.dir/OpenGL_Loaders/glad/src/glad.c.o -c /home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-src/external/hello_imgui/hello_imgui/external/OpenGL_Loaders/glad/src/glad.c

_deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external/CMakeFiles/glad.dir/OpenGL_Loaders/glad/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glad.dir/OpenGL_Loaders/glad/src/glad.c.i"
	cd /home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-src/external/hello_imgui/hello_imgui/external/OpenGL_Loaders/glad/src/glad.c > CMakeFiles/glad.dir/OpenGL_Loaders/glad/src/glad.c.i

_deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external/CMakeFiles/glad.dir/OpenGL_Loaders/glad/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glad.dir/OpenGL_Loaders/glad/src/glad.c.s"
	cd /home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-src/external/hello_imgui/hello_imgui/external/OpenGL_Loaders/glad/src/glad.c -o CMakeFiles/glad.dir/OpenGL_Loaders/glad/src/glad.c.s

# Object files for target glad
glad_OBJECTS = \
"CMakeFiles/glad.dir/OpenGL_Loaders/glad/src/glad.c.o"

# External object files for target glad
glad_EXTERNAL_OBJECTS =

_deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external/libglad.a: _deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external/CMakeFiles/glad.dir/OpenGL_Loaders/glad/src/glad.c.o
_deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external/libglad.a: _deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external/CMakeFiles/glad.dir/build.make
_deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external/libglad.a: _deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external/CMakeFiles/glad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/clement/Desktop/vielsprachig/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libglad.a"
	cd /home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external && $(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean_target.cmake
	cd /home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glad.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external/CMakeFiles/glad.dir/build: _deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external/libglad.a
.PHONY : _deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external/CMakeFiles/glad.dir/build

_deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external/CMakeFiles/glad.dir/clean:
	cd /home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external && $(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean.cmake
.PHONY : _deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external/CMakeFiles/glad.dir/clean

_deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external/CMakeFiles/glad.dir/depend:
	cd /home/clement/Desktop/vielsprachig/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/clement/Desktop/vielsprachig /home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-src/external/hello_imgui/hello_imgui/external /home/clement/Desktop/vielsprachig/build /home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external /home/clement/Desktop/vielsprachig/build/_deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external/CMakeFiles/glad.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/imgui_bundle-build/external/hello_imgui/hello_imgui/external/CMakeFiles/glad.dir/depend

