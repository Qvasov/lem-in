# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/dbennie/github/lem-in

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/dbennie/github/lem-in/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lem-in.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lem-in.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lem-in.dir/flags.make

CMakeFiles/lem-in.dir/src/main.c.o: CMakeFiles/lem-in.dir/flags.make
CMakeFiles/lem-in.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dbennie/github/lem-in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lem-in.dir/src/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem-in.dir/src/main.c.o   -c /Users/dbennie/github/lem-in/src/main.c

CMakeFiles/lem-in.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem-in.dir/src/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/dbennie/github/lem-in/src/main.c > CMakeFiles/lem-in.dir/src/main.c.i

CMakeFiles/lem-in.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem-in.dir/src/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/dbennie/github/lem-in/src/main.c -o CMakeFiles/lem-in.dir/src/main.c.s

CMakeFiles/lem-in.dir/src/ft_parse.c.o: CMakeFiles/lem-in.dir/flags.make
CMakeFiles/lem-in.dir/src/ft_parse.c.o: ../src/ft_parse.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dbennie/github/lem-in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/lem-in.dir/src/ft_parse.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem-in.dir/src/ft_parse.c.o   -c /Users/dbennie/github/lem-in/src/ft_parse.c

CMakeFiles/lem-in.dir/src/ft_parse.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem-in.dir/src/ft_parse.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/dbennie/github/lem-in/src/ft_parse.c > CMakeFiles/lem-in.dir/src/ft_parse.c.i

CMakeFiles/lem-in.dir/src/ft_parse.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem-in.dir/src/ft_parse.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/dbennie/github/lem-in/src/ft_parse.c -o CMakeFiles/lem-in.dir/src/ft_parse.c.s

CMakeFiles/lem-in.dir/src/ft_input.c.o: CMakeFiles/lem-in.dir/flags.make
CMakeFiles/lem-in.dir/src/ft_input.c.o: ../src/ft_input.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dbennie/github/lem-in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/lem-in.dir/src/ft_input.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem-in.dir/src/ft_input.c.o   -c /Users/dbennie/github/lem-in/src/ft_input.c

CMakeFiles/lem-in.dir/src/ft_input.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem-in.dir/src/ft_input.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/dbennie/github/lem-in/src/ft_input.c > CMakeFiles/lem-in.dir/src/ft_input.c.i

CMakeFiles/lem-in.dir/src/ft_input.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem-in.dir/src/ft_input.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/dbennie/github/lem-in/src/ft_input.c -o CMakeFiles/lem-in.dir/src/ft_input.c.s

CMakeFiles/lem-in.dir/src/ft_ants.c.o: CMakeFiles/lem-in.dir/flags.make
CMakeFiles/lem-in.dir/src/ft_ants.c.o: ../src/ft_ants.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dbennie/github/lem-in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/lem-in.dir/src/ft_ants.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem-in.dir/src/ft_ants.c.o   -c /Users/dbennie/github/lem-in/src/ft_ants.c

CMakeFiles/lem-in.dir/src/ft_ants.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem-in.dir/src/ft_ants.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/dbennie/github/lem-in/src/ft_ants.c > CMakeFiles/lem-in.dir/src/ft_ants.c.i

CMakeFiles/lem-in.dir/src/ft_ants.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem-in.dir/src/ft_ants.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/dbennie/github/lem-in/src/ft_ants.c -o CMakeFiles/lem-in.dir/src/ft_ants.c.s

CMakeFiles/lem-in.dir/src/ft_farm.c.o: CMakeFiles/lem-in.dir/flags.make
CMakeFiles/lem-in.dir/src/ft_farm.c.o: ../src/ft_farm.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dbennie/github/lem-in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/lem-in.dir/src/ft_farm.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem-in.dir/src/ft_farm.c.o   -c /Users/dbennie/github/lem-in/src/ft_farm.c

CMakeFiles/lem-in.dir/src/ft_farm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem-in.dir/src/ft_farm.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/dbennie/github/lem-in/src/ft_farm.c > CMakeFiles/lem-in.dir/src/ft_farm.c.i

CMakeFiles/lem-in.dir/src/ft_farm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem-in.dir/src/ft_farm.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/dbennie/github/lem-in/src/ft_farm.c -o CMakeFiles/lem-in.dir/src/ft_farm.c.s

# Object files for target lem-in
lem__in_OBJECTS = \
"CMakeFiles/lem-in.dir/src/main.c.o" \
"CMakeFiles/lem-in.dir/src/ft_parse.c.o" \
"CMakeFiles/lem-in.dir/src/ft_input.c.o" \
"CMakeFiles/lem-in.dir/src/ft_ants.c.o" \
"CMakeFiles/lem-in.dir/src/ft_farm.c.o"

# External object files for target lem-in
lem__in_EXTERNAL_OBJECTS =

lem-in: CMakeFiles/lem-in.dir/src/main.c.o
lem-in: CMakeFiles/lem-in.dir/src/ft_parse.c.o
lem-in: CMakeFiles/lem-in.dir/src/ft_input.c.o
lem-in: CMakeFiles/lem-in.dir/src/ft_ants.c.o
lem-in: CMakeFiles/lem-in.dir/src/ft_farm.c.o
lem-in: CMakeFiles/lem-in.dir/build.make
lem-in: /libft/libft.a
lem-in: CMakeFiles/lem-in.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/dbennie/github/lem-in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable lem-in"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lem-in.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lem-in.dir/build: lem-in

.PHONY : CMakeFiles/lem-in.dir/build

CMakeFiles/lem-in.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lem-in.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lem-in.dir/clean

CMakeFiles/lem-in.dir/depend:
	cd /Users/dbennie/github/lem-in/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dbennie/github/lem-in /Users/dbennie/github/lem-in /Users/dbennie/github/lem-in/cmake-build-debug /Users/dbennie/github/lem-in/cmake-build-debug /Users/dbennie/github/lem-in/cmake-build-debug/CMakeFiles/lem-in.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lem-in.dir/depend

