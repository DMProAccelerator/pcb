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

# Utility rule file for debug-server.

# Include the progress variables for this target.
include CMakeFiles/debug-server.dir/progress.make

CMakeFiles/debug-server: efm32-test
	JLinkGDBServer -device EFM32GG990F1024 -speed 4000 -if SWD

debug-server: CMakeFiles/debug-server
debug-server: CMakeFiles/debug-server.dir/build.make

.PHONY : debug-server

# Rule to build all files generated by this target.
CMakeFiles/debug-server.dir/build: debug-server

.PHONY : CMakeFiles/debug-server.dir/build

CMakeFiles/debug-server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/debug-server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/debug-server.dir/clean

CMakeFiles/debug-server.dir/depend:
	cd /Users/alfme/Documents/Docs/Skole/NTNU/5/dmpro/GitHub/pcb/mcu_clean/builds/efm32gg && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/alfme/Documents/Docs/Skole/NTNU/5/dmpro/GitHub/pcb/mcu_clean /Users/alfme/Documents/Docs/Skole/NTNU/5/dmpro/GitHub/pcb/mcu_clean /Users/alfme/Documents/Docs/Skole/NTNU/5/dmpro/GitHub/pcb/mcu_clean/builds/efm32gg /Users/alfme/Documents/Docs/Skole/NTNU/5/dmpro/GitHub/pcb/mcu_clean/builds/efm32gg /Users/alfme/Documents/Docs/Skole/NTNU/5/dmpro/GitHub/pcb/mcu_clean/builds/efm32gg/CMakeFiles/debug-server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/debug-server.dir/depend
