# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Users/creek/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Users/creek/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/creek/CLionProjects/untitled

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/creek/CLionProjects/untitled/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/untitled.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled.dir/flags.make

CMakeFiles/untitled.dir/main.c.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/creek/CLionProjects/untitled/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/untitled.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/untitled.dir/main.c.o   -c /Users/creek/CLionProjects/untitled/main.c

CMakeFiles/untitled.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/creek/CLionProjects/untitled/main.c > CMakeFiles/untitled.dir/main.c.i

CMakeFiles/untitled.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/creek/CLionProjects/untitled/main.c -o CMakeFiles/untitled.dir/main.c.s

CMakeFiles/untitled.dir/ft_ls/ft_ls.c.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/ft_ls/ft_ls.c.o: ../ft_ls/ft_ls.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/creek/CLionProjects/untitled/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/untitled.dir/ft_ls/ft_ls.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/untitled.dir/ft_ls/ft_ls.c.o   -c /Users/creek/CLionProjects/untitled/ft_ls/ft_ls.c

CMakeFiles/untitled.dir/ft_ls/ft_ls.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/ft_ls/ft_ls.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/creek/CLionProjects/untitled/ft_ls/ft_ls.c > CMakeFiles/untitled.dir/ft_ls/ft_ls.c.i

CMakeFiles/untitled.dir/ft_ls/ft_ls.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/ft_ls/ft_ls.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/creek/CLionProjects/untitled/ft_ls/ft_ls.c -o CMakeFiles/untitled.dir/ft_ls/ft_ls.c.s

CMakeFiles/untitled.dir/ft_ls/sorting.c.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/ft_ls/sorting.c.o: ../ft_ls/sorting.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/creek/CLionProjects/untitled/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/untitled.dir/ft_ls/sorting.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/untitled.dir/ft_ls/sorting.c.o   -c /Users/creek/CLionProjects/untitled/ft_ls/sorting.c

CMakeFiles/untitled.dir/ft_ls/sorting.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/ft_ls/sorting.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/creek/CLionProjects/untitled/ft_ls/sorting.c > CMakeFiles/untitled.dir/ft_ls/sorting.c.i

CMakeFiles/untitled.dir/ft_ls/sorting.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/ft_ls/sorting.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/creek/CLionProjects/untitled/ft_ls/sorting.c -o CMakeFiles/untitled.dir/ft_ls/sorting.c.s

CMakeFiles/untitled.dir/ft_ls/list_functions.c.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/ft_ls/list_functions.c.o: ../ft_ls/list_functions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/creek/CLionProjects/untitled/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/untitled.dir/ft_ls/list_functions.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/untitled.dir/ft_ls/list_functions.c.o   -c /Users/creek/CLionProjects/untitled/ft_ls/list_functions.c

CMakeFiles/untitled.dir/ft_ls/list_functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/ft_ls/list_functions.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/creek/CLionProjects/untitled/ft_ls/list_functions.c > CMakeFiles/untitled.dir/ft_ls/list_functions.c.i

CMakeFiles/untitled.dir/ft_ls/list_functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/ft_ls/list_functions.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/creek/CLionProjects/untitled/ft_ls/list_functions.c -o CMakeFiles/untitled.dir/ft_ls/list_functions.c.s

CMakeFiles/untitled.dir/ft_ls/output.c.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/ft_ls/output.c.o: ../ft_ls/output.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/creek/CLionProjects/untitled/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/untitled.dir/ft_ls/output.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/untitled.dir/ft_ls/output.c.o   -c /Users/creek/CLionProjects/untitled/ft_ls/output.c

CMakeFiles/untitled.dir/ft_ls/output.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/ft_ls/output.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/creek/CLionProjects/untitled/ft_ls/output.c > CMakeFiles/untitled.dir/ft_ls/output.c.i

CMakeFiles/untitled.dir/ft_ls/output.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/ft_ls/output.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/creek/CLionProjects/untitled/ft_ls/output.c -o CMakeFiles/untitled.dir/ft_ls/output.c.s

CMakeFiles/untitled.dir/ft_ls/rbt_add.c.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/ft_ls/rbt_add.c.o: ../ft_ls/rbt_add.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/creek/CLionProjects/untitled/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/untitled.dir/ft_ls/rbt_add.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/untitled.dir/ft_ls/rbt_add.c.o   -c /Users/creek/CLionProjects/untitled/ft_ls/rbt_add.c

CMakeFiles/untitled.dir/ft_ls/rbt_add.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/ft_ls/rbt_add.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/creek/CLionProjects/untitled/ft_ls/rbt_add.c > CMakeFiles/untitled.dir/ft_ls/rbt_add.c.i

CMakeFiles/untitled.dir/ft_ls/rbt_add.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/ft_ls/rbt_add.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/creek/CLionProjects/untitled/ft_ls/rbt_add.c -o CMakeFiles/untitled.dir/ft_ls/rbt_add.c.s

CMakeFiles/untitled.dir/ft_ls/ft_rbtnew.c.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/ft_ls/ft_rbtnew.c.o: ../ft_ls/ft_rbtnew.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/creek/CLionProjects/untitled/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/untitled.dir/ft_ls/ft_rbtnew.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/untitled.dir/ft_ls/ft_rbtnew.c.o   -c /Users/creek/CLionProjects/untitled/ft_ls/ft_rbtnew.c

CMakeFiles/untitled.dir/ft_ls/ft_rbtnew.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/ft_ls/ft_rbtnew.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/creek/CLionProjects/untitled/ft_ls/ft_rbtnew.c > CMakeFiles/untitled.dir/ft_ls/ft_rbtnew.c.i

CMakeFiles/untitled.dir/ft_ls/ft_rbtnew.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/ft_ls/ft_rbtnew.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/creek/CLionProjects/untitled/ft_ls/ft_rbtnew.c -o CMakeFiles/untitled.dir/ft_ls/ft_rbtnew.c.s

CMakeFiles/untitled.dir/ft_ls/ft_rbtclr.c.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/ft_ls/ft_rbtclr.c.o: ../ft_ls/ft_rbtclr.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/creek/CLionProjects/untitled/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/untitled.dir/ft_ls/ft_rbtclr.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/untitled.dir/ft_ls/ft_rbtclr.c.o   -c /Users/creek/CLionProjects/untitled/ft_ls/ft_rbtclr.c

CMakeFiles/untitled.dir/ft_ls/ft_rbtclr.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/ft_ls/ft_rbtclr.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/creek/CLionProjects/untitled/ft_ls/ft_rbtclr.c > CMakeFiles/untitled.dir/ft_ls/ft_rbtclr.c.i

CMakeFiles/untitled.dir/ft_ls/ft_rbtclr.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/ft_ls/ft_rbtclr.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/creek/CLionProjects/untitled/ft_ls/ft_rbtclr.c -o CMakeFiles/untitled.dir/ft_ls/ft_rbtclr.c.s

CMakeFiles/untitled.dir/ft_ls/ft_rbtroot.c.o: CMakeFiles/untitled.dir/flags.make
CMakeFiles/untitled.dir/ft_ls/ft_rbtroot.c.o: ../ft_ls/ft_rbtroot.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/creek/CLionProjects/untitled/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/untitled.dir/ft_ls/ft_rbtroot.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/untitled.dir/ft_ls/ft_rbtroot.c.o   -c /Users/creek/CLionProjects/untitled/ft_ls/ft_rbtroot.c

CMakeFiles/untitled.dir/ft_ls/ft_rbtroot.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled.dir/ft_ls/ft_rbtroot.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/creek/CLionProjects/untitled/ft_ls/ft_rbtroot.c > CMakeFiles/untitled.dir/ft_ls/ft_rbtroot.c.i

CMakeFiles/untitled.dir/ft_ls/ft_rbtroot.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled.dir/ft_ls/ft_rbtroot.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/creek/CLionProjects/untitled/ft_ls/ft_rbtroot.c -o CMakeFiles/untitled.dir/ft_ls/ft_rbtroot.c.s

# Object files for target untitled
untitled_OBJECTS = \
"CMakeFiles/untitled.dir/main.c.o" \
"CMakeFiles/untitled.dir/ft_ls/ft_ls.c.o" \
"CMakeFiles/untitled.dir/ft_ls/sorting.c.o" \
"CMakeFiles/untitled.dir/ft_ls/list_functions.c.o" \
"CMakeFiles/untitled.dir/ft_ls/output.c.o" \
"CMakeFiles/untitled.dir/ft_ls/rbt_add.c.o" \
"CMakeFiles/untitled.dir/ft_ls/ft_rbtnew.c.o" \
"CMakeFiles/untitled.dir/ft_ls/ft_rbtclr.c.o" \
"CMakeFiles/untitled.dir/ft_ls/ft_rbtroot.c.o"

# External object files for target untitled
untitled_EXTERNAL_OBJECTS =

untitled: CMakeFiles/untitled.dir/main.c.o
untitled: CMakeFiles/untitled.dir/ft_ls/ft_ls.c.o
untitled: CMakeFiles/untitled.dir/ft_ls/sorting.c.o
untitled: CMakeFiles/untitled.dir/ft_ls/list_functions.c.o
untitled: CMakeFiles/untitled.dir/ft_ls/output.c.o
untitled: CMakeFiles/untitled.dir/ft_ls/rbt_add.c.o
untitled: CMakeFiles/untitled.dir/ft_ls/ft_rbtnew.c.o
untitled: CMakeFiles/untitled.dir/ft_ls/ft_rbtclr.c.o
untitled: CMakeFiles/untitled.dir/ft_ls/ft_rbtroot.c.o
untitled: CMakeFiles/untitled.dir/build.make
untitled: ../libft/libft.a
untitled: CMakeFiles/untitled.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/creek/CLionProjects/untitled/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking C executable untitled"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/untitled.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled.dir/build: untitled

.PHONY : CMakeFiles/untitled.dir/build

CMakeFiles/untitled.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/untitled.dir/cmake_clean.cmake
.PHONY : CMakeFiles/untitled.dir/clean

CMakeFiles/untitled.dir/depend:
	cd /Users/creek/CLionProjects/untitled/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/creek/CLionProjects/untitled /Users/creek/CLionProjects/untitled /Users/creek/CLionProjects/untitled/cmake-build-debug /Users/creek/CLionProjects/untitled/cmake-build-debug /Users/creek/CLionProjects/untitled/cmake-build-debug/CMakeFiles/untitled.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/untitled.dir/depend

