# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nelsonfrew/branch_and_bound

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nelsonfrew/branch_and_bound

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/nelsonfrew/branch_and_bound/CMakeFiles /home/nelsonfrew/branch_and_bound/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/nelsonfrew/branch_and_bound/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named branch_and_bound_test

# Build rule for target.
branch_and_bound_test: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 branch_and_bound_test
.PHONY : branch_and_bound_test

# fast build rule for target.
branch_and_bound_test/fast:
	$(MAKE) -f CMakeFiles/branch_and_bound_test.dir/build.make CMakeFiles/branch_and_bound_test.dir/build
.PHONY : branch_and_bound_test/fast

branch_and_bound_test.o: branch_and_bound_test.cpp.o

.PHONY : branch_and_bound_test.o

# target to build an object file
branch_and_bound_test.cpp.o:
	$(MAKE) -f CMakeFiles/branch_and_bound_test.dir/build.make CMakeFiles/branch_and_bound_test.dir/branch_and_bound_test.cpp.o
.PHONY : branch_and_bound_test.cpp.o

branch_and_bound_test.i: branch_and_bound_test.cpp.i

.PHONY : branch_and_bound_test.i

# target to preprocess a source file
branch_and_bound_test.cpp.i:
	$(MAKE) -f CMakeFiles/branch_and_bound_test.dir/build.make CMakeFiles/branch_and_bound_test.dir/branch_and_bound_test.cpp.i
.PHONY : branch_and_bound_test.cpp.i

branch_and_bound_test.s: branch_and_bound_test.cpp.s

.PHONY : branch_and_bound_test.s

# target to generate assembly for a file
branch_and_bound_test.cpp.s:
	$(MAKE) -f CMakeFiles/branch_and_bound_test.dir/build.make CMakeFiles/branch_and_bound_test.dir/branch_and_bound_test.cpp.s
.PHONY : branch_and_bound_test.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... branch_and_bound_test"
	@echo "... edit_cache"
	@echo "... branch_and_bound_test.o"
	@echo "... branch_and_bound_test.i"
	@echo "... branch_and_bound_test.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

