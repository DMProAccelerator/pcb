# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /Users/alfme/Documents/Docs/Programmering/builds/cmake/bin/cmake

# The command to remove a file.
RM = /Users/alfme/Documents/Docs/Programmering/builds/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/alfme/efm32-base

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/alfme/efm32-base/builds/efm32gg

# Utility rule file for e.

# Include the progress variables for this target.
include CMakeFiles/e.dir/progress.make

CMakeFiles/e:
	JLinkExe -device EFM32GG990F1024 -speed 4000 -if SWD -CommanderScript /Users/alfme/efm32-base/toolchain/erase.jlink

e : CMakeFiles/e
e : CMakeFiles/e.dir/build.make

.PHONY : e

# Rule to build all files generated by this target.
CMakeFiles/e.dir/build: e

.PHONY : CMakeFiles/e.dir/build

CMakeFiles/e.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/e.dir/cmake_clean.cmake
.PHONY : CMakeFiles/e.dir/clean

CMakeFiles/e.dir/depend:
	cd /Users/alfme/efm32-base/builds/efm32gg && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/alfme/efm32-base /Users/alfme/efm32-base /Users/alfme/efm32-base/builds/efm32gg /Users/alfme/efm32-base/builds/efm32gg /Users/alfme/efm32-base/builds/efm32gg/CMakeFiles/e.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/e.dir/depend

