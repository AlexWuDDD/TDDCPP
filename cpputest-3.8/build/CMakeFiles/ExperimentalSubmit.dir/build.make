# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/e823551/Documents/TDDCPP/cpputest-3.8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/e823551/Documents/TDDCPP/cpputest-3.8/build

# Utility rule file for ExperimentalSubmit.

# Include the progress variables for this target.
include CMakeFiles/ExperimentalSubmit.dir/progress.make

CMakeFiles/ExperimentalSubmit:
	/Applications/CMake.app/Contents/bin/ctest -D ExperimentalSubmit

ExperimentalSubmit: CMakeFiles/ExperimentalSubmit
ExperimentalSubmit: CMakeFiles/ExperimentalSubmit.dir/build.make

.PHONY : ExperimentalSubmit

# Rule to build all files generated by this target.
CMakeFiles/ExperimentalSubmit.dir/build: ExperimentalSubmit

.PHONY : CMakeFiles/ExperimentalSubmit.dir/build

CMakeFiles/ExperimentalSubmit.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ExperimentalSubmit.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ExperimentalSubmit.dir/clean

CMakeFiles/ExperimentalSubmit.dir/depend:
	cd /Users/e823551/Documents/TDDCPP/cpputest-3.8/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/e823551/Documents/TDDCPP/cpputest-3.8 /Users/e823551/Documents/TDDCPP/cpputest-3.8 /Users/e823551/Documents/TDDCPP/cpputest-3.8/build /Users/e823551/Documents/TDDCPP/cpputest-3.8/build /Users/e823551/Documents/TDDCPP/cpputest-3.8/build/CMakeFiles/ExperimentalSubmit.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ExperimentalSubmit.dir/depend

