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
CMAKE_SOURCE_DIR = /Users/e823551/Documents/TDDCPP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/e823551/Documents/TDDCPP/build

# Include any dependencies generated for this target.
include CMakeFiles/testGMOCK.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testGMOCK.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testGMOCK.dir/flags.make

CMakeFiles/testGMOCK.dir/src/c2/1/main.cpp.o: CMakeFiles/testGMOCK.dir/flags.make
CMakeFiles/testGMOCK.dir/src/c2/1/main.cpp.o: ../src/c2/1/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/e823551/Documents/TDDCPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testGMOCK.dir/src/c2/1/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testGMOCK.dir/src/c2/1/main.cpp.o -c /Users/e823551/Documents/TDDCPP/src/c2/1/main.cpp

CMakeFiles/testGMOCK.dir/src/c2/1/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testGMOCK.dir/src/c2/1/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/e823551/Documents/TDDCPP/src/c2/1/main.cpp > CMakeFiles/testGMOCK.dir/src/c2/1/main.cpp.i

CMakeFiles/testGMOCK.dir/src/c2/1/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testGMOCK.dir/src/c2/1/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/e823551/Documents/TDDCPP/src/c2/1/main.cpp -o CMakeFiles/testGMOCK.dir/src/c2/1/main.cpp.s

# Object files for target testGMOCK
testGMOCK_OBJECTS = \
"CMakeFiles/testGMOCK.dir/src/c2/1/main.cpp.o"

# External object files for target testGMOCK
testGMOCK_EXTERNAL_OBJECTS =

testGMOCK: CMakeFiles/testGMOCK.dir/src/c2/1/main.cpp.o
testGMOCK: CMakeFiles/testGMOCK.dir/build.make
testGMOCK: CMakeFiles/testGMOCK.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/e823551/Documents/TDDCPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testGMOCK"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testGMOCK.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testGMOCK.dir/build: testGMOCK

.PHONY : CMakeFiles/testGMOCK.dir/build

CMakeFiles/testGMOCK.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testGMOCK.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testGMOCK.dir/clean

CMakeFiles/testGMOCK.dir/depend:
	cd /Users/e823551/Documents/TDDCPP/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/e823551/Documents/TDDCPP /Users/e823551/Documents/TDDCPP /Users/e823551/Documents/TDDCPP/build /Users/e823551/Documents/TDDCPP/build /Users/e823551/Documents/TDDCPP/build/CMakeFiles/testGMOCK.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testGMOCK.dir/depend

