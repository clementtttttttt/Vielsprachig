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
include libarchive/tar/CMakeFiles/bsdtar.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libarchive/tar/CMakeFiles/bsdtar.dir/compiler_depend.make

# Include the progress variables for this target.
include libarchive/tar/CMakeFiles/bsdtar.dir/progress.make

# Include the compile flags for this target's objects.
include libarchive/tar/CMakeFiles/bsdtar.dir/flags.make

libarchive/tar/CMakeFiles/bsdtar.dir/bsdtar.c.o: libarchive/tar/CMakeFiles/bsdtar.dir/flags.make
libarchive/tar/CMakeFiles/bsdtar.dir/bsdtar.c.o: libarchive/tar/CMakeFiles/bsdtar.dir/includes_C.rsp
libarchive/tar/CMakeFiles/bsdtar.dir/bsdtar.c.o: /home/clement/Desktop/vielsprachig/libarchive/tar/bsdtar.c
libarchive/tar/CMakeFiles/bsdtar.dir/bsdtar.c.o: libarchive/tar/CMakeFiles/bsdtar.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clement/Desktop/vielsprachig/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object libarchive/tar/CMakeFiles/bsdtar.dir/bsdtar.c.o"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT libarchive/tar/CMakeFiles/bsdtar.dir/bsdtar.c.o -MF CMakeFiles/bsdtar.dir/bsdtar.c.o.d -o CMakeFiles/bsdtar.dir/bsdtar.c.o -c /home/clement/Desktop/vielsprachig/libarchive/tar/bsdtar.c

libarchive/tar/CMakeFiles/bsdtar.dir/bsdtar.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bsdtar.dir/bsdtar.c.i"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/clement/Desktop/vielsprachig/libarchive/tar/bsdtar.c > CMakeFiles/bsdtar.dir/bsdtar.c.i

libarchive/tar/CMakeFiles/bsdtar.dir/bsdtar.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bsdtar.dir/bsdtar.c.s"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/clement/Desktop/vielsprachig/libarchive/tar/bsdtar.c -o CMakeFiles/bsdtar.dir/bsdtar.c.s

libarchive/tar/CMakeFiles/bsdtar.dir/cmdline.c.o: libarchive/tar/CMakeFiles/bsdtar.dir/flags.make
libarchive/tar/CMakeFiles/bsdtar.dir/cmdline.c.o: libarchive/tar/CMakeFiles/bsdtar.dir/includes_C.rsp
libarchive/tar/CMakeFiles/bsdtar.dir/cmdline.c.o: /home/clement/Desktop/vielsprachig/libarchive/tar/cmdline.c
libarchive/tar/CMakeFiles/bsdtar.dir/cmdline.c.o: libarchive/tar/CMakeFiles/bsdtar.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clement/Desktop/vielsprachig/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object libarchive/tar/CMakeFiles/bsdtar.dir/cmdline.c.o"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT libarchive/tar/CMakeFiles/bsdtar.dir/cmdline.c.o -MF CMakeFiles/bsdtar.dir/cmdline.c.o.d -o CMakeFiles/bsdtar.dir/cmdline.c.o -c /home/clement/Desktop/vielsprachig/libarchive/tar/cmdline.c

libarchive/tar/CMakeFiles/bsdtar.dir/cmdline.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bsdtar.dir/cmdline.c.i"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/clement/Desktop/vielsprachig/libarchive/tar/cmdline.c > CMakeFiles/bsdtar.dir/cmdline.c.i

libarchive/tar/CMakeFiles/bsdtar.dir/cmdline.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bsdtar.dir/cmdline.c.s"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/clement/Desktop/vielsprachig/libarchive/tar/cmdline.c -o CMakeFiles/bsdtar.dir/cmdline.c.s

libarchive/tar/CMakeFiles/bsdtar.dir/creation_set.c.o: libarchive/tar/CMakeFiles/bsdtar.dir/flags.make
libarchive/tar/CMakeFiles/bsdtar.dir/creation_set.c.o: libarchive/tar/CMakeFiles/bsdtar.dir/includes_C.rsp
libarchive/tar/CMakeFiles/bsdtar.dir/creation_set.c.o: /home/clement/Desktop/vielsprachig/libarchive/tar/creation_set.c
libarchive/tar/CMakeFiles/bsdtar.dir/creation_set.c.o: libarchive/tar/CMakeFiles/bsdtar.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clement/Desktop/vielsprachig/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object libarchive/tar/CMakeFiles/bsdtar.dir/creation_set.c.o"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT libarchive/tar/CMakeFiles/bsdtar.dir/creation_set.c.o -MF CMakeFiles/bsdtar.dir/creation_set.c.o.d -o CMakeFiles/bsdtar.dir/creation_set.c.o -c /home/clement/Desktop/vielsprachig/libarchive/tar/creation_set.c

libarchive/tar/CMakeFiles/bsdtar.dir/creation_set.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bsdtar.dir/creation_set.c.i"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/clement/Desktop/vielsprachig/libarchive/tar/creation_set.c > CMakeFiles/bsdtar.dir/creation_set.c.i

libarchive/tar/CMakeFiles/bsdtar.dir/creation_set.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bsdtar.dir/creation_set.c.s"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/clement/Desktop/vielsprachig/libarchive/tar/creation_set.c -o CMakeFiles/bsdtar.dir/creation_set.c.s

libarchive/tar/CMakeFiles/bsdtar.dir/read.c.o: libarchive/tar/CMakeFiles/bsdtar.dir/flags.make
libarchive/tar/CMakeFiles/bsdtar.dir/read.c.o: libarchive/tar/CMakeFiles/bsdtar.dir/includes_C.rsp
libarchive/tar/CMakeFiles/bsdtar.dir/read.c.o: /home/clement/Desktop/vielsprachig/libarchive/tar/read.c
libarchive/tar/CMakeFiles/bsdtar.dir/read.c.o: libarchive/tar/CMakeFiles/bsdtar.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clement/Desktop/vielsprachig/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object libarchive/tar/CMakeFiles/bsdtar.dir/read.c.o"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT libarchive/tar/CMakeFiles/bsdtar.dir/read.c.o -MF CMakeFiles/bsdtar.dir/read.c.o.d -o CMakeFiles/bsdtar.dir/read.c.o -c /home/clement/Desktop/vielsprachig/libarchive/tar/read.c

libarchive/tar/CMakeFiles/bsdtar.dir/read.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bsdtar.dir/read.c.i"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/clement/Desktop/vielsprachig/libarchive/tar/read.c > CMakeFiles/bsdtar.dir/read.c.i

libarchive/tar/CMakeFiles/bsdtar.dir/read.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bsdtar.dir/read.c.s"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/clement/Desktop/vielsprachig/libarchive/tar/read.c -o CMakeFiles/bsdtar.dir/read.c.s

libarchive/tar/CMakeFiles/bsdtar.dir/subst.c.o: libarchive/tar/CMakeFiles/bsdtar.dir/flags.make
libarchive/tar/CMakeFiles/bsdtar.dir/subst.c.o: libarchive/tar/CMakeFiles/bsdtar.dir/includes_C.rsp
libarchive/tar/CMakeFiles/bsdtar.dir/subst.c.o: /home/clement/Desktop/vielsprachig/libarchive/tar/subst.c
libarchive/tar/CMakeFiles/bsdtar.dir/subst.c.o: libarchive/tar/CMakeFiles/bsdtar.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clement/Desktop/vielsprachig/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object libarchive/tar/CMakeFiles/bsdtar.dir/subst.c.o"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT libarchive/tar/CMakeFiles/bsdtar.dir/subst.c.o -MF CMakeFiles/bsdtar.dir/subst.c.o.d -o CMakeFiles/bsdtar.dir/subst.c.o -c /home/clement/Desktop/vielsprachig/libarchive/tar/subst.c

libarchive/tar/CMakeFiles/bsdtar.dir/subst.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bsdtar.dir/subst.c.i"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/clement/Desktop/vielsprachig/libarchive/tar/subst.c > CMakeFiles/bsdtar.dir/subst.c.i

libarchive/tar/CMakeFiles/bsdtar.dir/subst.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bsdtar.dir/subst.c.s"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/clement/Desktop/vielsprachig/libarchive/tar/subst.c -o CMakeFiles/bsdtar.dir/subst.c.s

libarchive/tar/CMakeFiles/bsdtar.dir/util.c.o: libarchive/tar/CMakeFiles/bsdtar.dir/flags.make
libarchive/tar/CMakeFiles/bsdtar.dir/util.c.o: libarchive/tar/CMakeFiles/bsdtar.dir/includes_C.rsp
libarchive/tar/CMakeFiles/bsdtar.dir/util.c.o: /home/clement/Desktop/vielsprachig/libarchive/tar/util.c
libarchive/tar/CMakeFiles/bsdtar.dir/util.c.o: libarchive/tar/CMakeFiles/bsdtar.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clement/Desktop/vielsprachig/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object libarchive/tar/CMakeFiles/bsdtar.dir/util.c.o"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT libarchive/tar/CMakeFiles/bsdtar.dir/util.c.o -MF CMakeFiles/bsdtar.dir/util.c.o.d -o CMakeFiles/bsdtar.dir/util.c.o -c /home/clement/Desktop/vielsprachig/libarchive/tar/util.c

libarchive/tar/CMakeFiles/bsdtar.dir/util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bsdtar.dir/util.c.i"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/clement/Desktop/vielsprachig/libarchive/tar/util.c > CMakeFiles/bsdtar.dir/util.c.i

libarchive/tar/CMakeFiles/bsdtar.dir/util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bsdtar.dir/util.c.s"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/clement/Desktop/vielsprachig/libarchive/tar/util.c -o CMakeFiles/bsdtar.dir/util.c.s

libarchive/tar/CMakeFiles/bsdtar.dir/write.c.o: libarchive/tar/CMakeFiles/bsdtar.dir/flags.make
libarchive/tar/CMakeFiles/bsdtar.dir/write.c.o: libarchive/tar/CMakeFiles/bsdtar.dir/includes_C.rsp
libarchive/tar/CMakeFiles/bsdtar.dir/write.c.o: /home/clement/Desktop/vielsprachig/libarchive/tar/write.c
libarchive/tar/CMakeFiles/bsdtar.dir/write.c.o: libarchive/tar/CMakeFiles/bsdtar.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clement/Desktop/vielsprachig/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object libarchive/tar/CMakeFiles/bsdtar.dir/write.c.o"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT libarchive/tar/CMakeFiles/bsdtar.dir/write.c.o -MF CMakeFiles/bsdtar.dir/write.c.o.d -o CMakeFiles/bsdtar.dir/write.c.o -c /home/clement/Desktop/vielsprachig/libarchive/tar/write.c

libarchive/tar/CMakeFiles/bsdtar.dir/write.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bsdtar.dir/write.c.i"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/clement/Desktop/vielsprachig/libarchive/tar/write.c > CMakeFiles/bsdtar.dir/write.c.i

libarchive/tar/CMakeFiles/bsdtar.dir/write.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bsdtar.dir/write.c.s"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/clement/Desktop/vielsprachig/libarchive/tar/write.c -o CMakeFiles/bsdtar.dir/write.c.s

libarchive/tar/CMakeFiles/bsdtar.dir/__/libarchive_fe/err.c.o: libarchive/tar/CMakeFiles/bsdtar.dir/flags.make
libarchive/tar/CMakeFiles/bsdtar.dir/__/libarchive_fe/err.c.o: libarchive/tar/CMakeFiles/bsdtar.dir/includes_C.rsp
libarchive/tar/CMakeFiles/bsdtar.dir/__/libarchive_fe/err.c.o: /home/clement/Desktop/vielsprachig/libarchive/libarchive_fe/err.c
libarchive/tar/CMakeFiles/bsdtar.dir/__/libarchive_fe/err.c.o: libarchive/tar/CMakeFiles/bsdtar.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clement/Desktop/vielsprachig/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object libarchive/tar/CMakeFiles/bsdtar.dir/__/libarchive_fe/err.c.o"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT libarchive/tar/CMakeFiles/bsdtar.dir/__/libarchive_fe/err.c.o -MF CMakeFiles/bsdtar.dir/__/libarchive_fe/err.c.o.d -o CMakeFiles/bsdtar.dir/__/libarchive_fe/err.c.o -c /home/clement/Desktop/vielsprachig/libarchive/libarchive_fe/err.c

libarchive/tar/CMakeFiles/bsdtar.dir/__/libarchive_fe/err.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bsdtar.dir/__/libarchive_fe/err.c.i"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/clement/Desktop/vielsprachig/libarchive/libarchive_fe/err.c > CMakeFiles/bsdtar.dir/__/libarchive_fe/err.c.i

libarchive/tar/CMakeFiles/bsdtar.dir/__/libarchive_fe/err.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bsdtar.dir/__/libarchive_fe/err.c.s"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/clement/Desktop/vielsprachig/libarchive/libarchive_fe/err.c -o CMakeFiles/bsdtar.dir/__/libarchive_fe/err.c.s

libarchive/tar/CMakeFiles/bsdtar.dir/__/libarchive_fe/line_reader.c.o: libarchive/tar/CMakeFiles/bsdtar.dir/flags.make
libarchive/tar/CMakeFiles/bsdtar.dir/__/libarchive_fe/line_reader.c.o: libarchive/tar/CMakeFiles/bsdtar.dir/includes_C.rsp
libarchive/tar/CMakeFiles/bsdtar.dir/__/libarchive_fe/line_reader.c.o: /home/clement/Desktop/vielsprachig/libarchive/libarchive_fe/line_reader.c
libarchive/tar/CMakeFiles/bsdtar.dir/__/libarchive_fe/line_reader.c.o: libarchive/tar/CMakeFiles/bsdtar.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clement/Desktop/vielsprachig/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object libarchive/tar/CMakeFiles/bsdtar.dir/__/libarchive_fe/line_reader.c.o"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT libarchive/tar/CMakeFiles/bsdtar.dir/__/libarchive_fe/line_reader.c.o -MF CMakeFiles/bsdtar.dir/__/libarchive_fe/line_reader.c.o.d -o CMakeFiles/bsdtar.dir/__/libarchive_fe/line_reader.c.o -c /home/clement/Desktop/vielsprachig/libarchive/libarchive_fe/line_reader.c

libarchive/tar/CMakeFiles/bsdtar.dir/__/libarchive_fe/line_reader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bsdtar.dir/__/libarchive_fe/line_reader.c.i"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/clement/Desktop/vielsprachig/libarchive/libarchive_fe/line_reader.c > CMakeFiles/bsdtar.dir/__/libarchive_fe/line_reader.c.i

libarchive/tar/CMakeFiles/bsdtar.dir/__/libarchive_fe/line_reader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bsdtar.dir/__/libarchive_fe/line_reader.c.s"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/clement/Desktop/vielsprachig/libarchive/libarchive_fe/line_reader.c -o CMakeFiles/bsdtar.dir/__/libarchive_fe/line_reader.c.s

libarchive/tar/CMakeFiles/bsdtar.dir/__/libarchive_fe/passphrase.c.o: libarchive/tar/CMakeFiles/bsdtar.dir/flags.make
libarchive/tar/CMakeFiles/bsdtar.dir/__/libarchive_fe/passphrase.c.o: libarchive/tar/CMakeFiles/bsdtar.dir/includes_C.rsp
libarchive/tar/CMakeFiles/bsdtar.dir/__/libarchive_fe/passphrase.c.o: /home/clement/Desktop/vielsprachig/libarchive/libarchive_fe/passphrase.c
libarchive/tar/CMakeFiles/bsdtar.dir/__/libarchive_fe/passphrase.c.o: libarchive/tar/CMakeFiles/bsdtar.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clement/Desktop/vielsprachig/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object libarchive/tar/CMakeFiles/bsdtar.dir/__/libarchive_fe/passphrase.c.o"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT libarchive/tar/CMakeFiles/bsdtar.dir/__/libarchive_fe/passphrase.c.o -MF CMakeFiles/bsdtar.dir/__/libarchive_fe/passphrase.c.o.d -o CMakeFiles/bsdtar.dir/__/libarchive_fe/passphrase.c.o -c /home/clement/Desktop/vielsprachig/libarchive/libarchive_fe/passphrase.c

libarchive/tar/CMakeFiles/bsdtar.dir/__/libarchive_fe/passphrase.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bsdtar.dir/__/libarchive_fe/passphrase.c.i"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/clement/Desktop/vielsprachig/libarchive/libarchive_fe/passphrase.c > CMakeFiles/bsdtar.dir/__/libarchive_fe/passphrase.c.i

libarchive/tar/CMakeFiles/bsdtar.dir/__/libarchive_fe/passphrase.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bsdtar.dir/__/libarchive_fe/passphrase.c.s"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && /usr/lib/emscripten/emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/clement/Desktop/vielsprachig/libarchive/libarchive_fe/passphrase.c -o CMakeFiles/bsdtar.dir/__/libarchive_fe/passphrase.c.s

# Object files for target bsdtar
bsdtar_OBJECTS = \
"CMakeFiles/bsdtar.dir/bsdtar.c.o" \
"CMakeFiles/bsdtar.dir/cmdline.c.o" \
"CMakeFiles/bsdtar.dir/creation_set.c.o" \
"CMakeFiles/bsdtar.dir/read.c.o" \
"CMakeFiles/bsdtar.dir/subst.c.o" \
"CMakeFiles/bsdtar.dir/util.c.o" \
"CMakeFiles/bsdtar.dir/write.c.o" \
"CMakeFiles/bsdtar.dir/__/libarchive_fe/err.c.o" \
"CMakeFiles/bsdtar.dir/__/libarchive_fe/line_reader.c.o" \
"CMakeFiles/bsdtar.dir/__/libarchive_fe/passphrase.c.o"

# External object files for target bsdtar
bsdtar_EXTERNAL_OBJECTS =

libarchive/bin/bsdtar.html: libarchive/tar/CMakeFiles/bsdtar.dir/bsdtar.c.o
libarchive/bin/bsdtar.html: libarchive/tar/CMakeFiles/bsdtar.dir/cmdline.c.o
libarchive/bin/bsdtar.html: libarchive/tar/CMakeFiles/bsdtar.dir/creation_set.c.o
libarchive/bin/bsdtar.html: libarchive/tar/CMakeFiles/bsdtar.dir/read.c.o
libarchive/bin/bsdtar.html: libarchive/tar/CMakeFiles/bsdtar.dir/subst.c.o
libarchive/bin/bsdtar.html: libarchive/tar/CMakeFiles/bsdtar.dir/util.c.o
libarchive/bin/bsdtar.html: libarchive/tar/CMakeFiles/bsdtar.dir/write.c.o
libarchive/bin/bsdtar.html: libarchive/tar/CMakeFiles/bsdtar.dir/__/libarchive_fe/err.c.o
libarchive/bin/bsdtar.html: libarchive/tar/CMakeFiles/bsdtar.dir/__/libarchive_fe/line_reader.c.o
libarchive/bin/bsdtar.html: libarchive/tar/CMakeFiles/bsdtar.dir/__/libarchive_fe/passphrase.c.o
libarchive/bin/bsdtar.html: libarchive/tar/CMakeFiles/bsdtar.dir/build.make
libarchive/bin/bsdtar.html: libarchive/libarchive/libarchive.a
libarchive/bin/bsdtar.html: /home/clement/.emscripten_cache/sysroot/lib/wasm32-emscripten/libz.a
libarchive/bin/bsdtar.html: libarchive/tar/CMakeFiles/bsdtar.dir/linkLibs.rsp
libarchive/bin/bsdtar.html: libarchive/tar/CMakeFiles/bsdtar.dir/objects1.rsp
libarchive/bin/bsdtar.html: libarchive/tar/CMakeFiles/bsdtar.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/clement/Desktop/vielsprachig/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking C executable ../bin/bsdtar.html"
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bsdtar.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libarchive/tar/CMakeFiles/bsdtar.dir/build: libarchive/bin/bsdtar.html
.PHONY : libarchive/tar/CMakeFiles/bsdtar.dir/build

libarchive/tar/CMakeFiles/bsdtar.dir/clean:
	cd /home/clement/Desktop/vielsprachig/build/libarchive/tar && $(CMAKE_COMMAND) -P CMakeFiles/bsdtar.dir/cmake_clean.cmake
.PHONY : libarchive/tar/CMakeFiles/bsdtar.dir/clean

libarchive/tar/CMakeFiles/bsdtar.dir/depend:
	cd /home/clement/Desktop/vielsprachig/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/clement/Desktop/vielsprachig /home/clement/Desktop/vielsprachig/libarchive/tar /home/clement/Desktop/vielsprachig/build /home/clement/Desktop/vielsprachig/build/libarchive/tar /home/clement/Desktop/vielsprachig/build/libarchive/tar/CMakeFiles/bsdtar.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libarchive/tar/CMakeFiles/bsdtar.dir/depend

