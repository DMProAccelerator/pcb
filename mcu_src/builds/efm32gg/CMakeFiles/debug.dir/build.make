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
CMAKE_SOURCE_DIR = /Users/alfme/Documents/Docs/Skole/NTNU/5/dmpro/GitHub/pcb/mcu_clean

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/alfme/Documents/Docs/Skole/NTNU/5/dmpro/GitHub/pcb/mcu_clean/builds/efm32gg

# Utility rule file for debug.

# Include the progress variables for this target.
include CMakeFiles/debug.dir/progress.make

CMakeFiles/debug: efm32-test
	arm-none-eabi-gdb -tui -command /Users/alfme/Documents/Docs/Skole/NTNU/5/dmpro/GitHub/pcb/mcu_clean/toolchain/remote.gdbconf /Users/alfme/Documents/Docs/Skole/NTNU/5/dmpro/GitHub/pcb/mcu_clean/builds/efm32gg/efm32-test

debug: CMakeFiles/debug
debug: CMakeFiles/debug.dir/build.make

.PHONY : debug

# Rule to build all files generated by this target.
CMakeFiles/debug.dir/build: debug

.PHONY : CMakeFiles/debug.dir/build

CMakeFiles/debug.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/debug.dir/cmake_clean.cmake
.PHONY : CMakeFiles/debug.dir/clean

CMakeFiles/debug.dir/depend:
	cd /Users/alfme/Documents/Docs/Skole/NTNU/5/dmpro/GitHub/pcb/mcu_clean/builds/efm32gg && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/alfme/Documents/Docs/Skole/NTNU/5/dmpro/GitHub/pcb/mcu_clean /Users/alfme/Documents/Docs/Skole/NTNU/5/dmpro/GitHub/pcb/mcu_clean /Users/alfme/Documents/Docs/Skole/NTNU/5/dmpro/GitHub/pcb/mcu_clean/builds/efm32gg /Users/alfme/Documents/Docs/Skole/NTNU/5/dmpro/GitHub/pcb/mcu_clean/builds/efm32gg /Users/alfme/Documents/Docs/Skole/NTNU/5/dmpro/GitHub/pcb/mcu_clean/builds/efm32gg/CMakeFiles/debug.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/debug.dir/depend

