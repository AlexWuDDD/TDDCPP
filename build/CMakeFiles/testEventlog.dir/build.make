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
include CMakeFiles/testEventlog.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testEventlog.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testEventlog.dir/flags.make

CMakeFiles/testEventlog.dir/src/eventlog/Eventlog.cpp.o: CMakeFiles/testEventlog.dir/flags.make
CMakeFiles/testEventlog.dir/src/eventlog/Eventlog.cpp.o: ../src/eventlog/Eventlog.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/e823551/Documents/TDDCPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testEventlog.dir/src/eventlog/Eventlog.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testEventlog.dir/src/eventlog/Eventlog.cpp.o -c /Users/e823551/Documents/TDDCPP/src/eventlog/Eventlog.cpp

CMakeFiles/testEventlog.dir/src/eventlog/Eventlog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testEventlog.dir/src/eventlog/Eventlog.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/e823551/Documents/TDDCPP/src/eventlog/Eventlog.cpp > CMakeFiles/testEventlog.dir/src/eventlog/Eventlog.cpp.i

CMakeFiles/testEventlog.dir/src/eventlog/Eventlog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testEventlog.dir/src/eventlog/Eventlog.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/e823551/Documents/TDDCPP/src/eventlog/Eventlog.cpp -o CMakeFiles/testEventlog.dir/src/eventlog/Eventlog.cpp.s

CMakeFiles/testEventlog.dir/src/eventlog/eventlogTest.cpp.o: CMakeFiles/testEventlog.dir/flags.make
CMakeFiles/testEventlog.dir/src/eventlog/eventlogTest.cpp.o: ../src/eventlog/eventlogTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/e823551/Documents/TDDCPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/testEventlog.dir/src/eventlog/eventlogTest.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testEventlog.dir/src/eventlog/eventlogTest.cpp.o -c /Users/e823551/Documents/TDDCPP/src/eventlog/eventlogTest.cpp

CMakeFiles/testEventlog.dir/src/eventlog/eventlogTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testEventlog.dir/src/eventlog/eventlogTest.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/e823551/Documents/TDDCPP/src/eventlog/eventlogTest.cpp > CMakeFiles/testEventlog.dir/src/eventlog/eventlogTest.cpp.i

CMakeFiles/testEventlog.dir/src/eventlog/eventlogTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testEventlog.dir/src/eventlog/eventlogTest.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/e823551/Documents/TDDCPP/src/eventlog/eventlogTest.cpp -o CMakeFiles/testEventlog.dir/src/eventlog/eventlogTest.cpp.s

CMakeFiles/testEventlog.dir/src/common/Common.cpp.o: CMakeFiles/testEventlog.dir/flags.make
CMakeFiles/testEventlog.dir/src/common/Common.cpp.o: ../src/common/Common.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/e823551/Documents/TDDCPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/testEventlog.dir/src/common/Common.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testEventlog.dir/src/common/Common.cpp.o -c /Users/e823551/Documents/TDDCPP/src/common/Common.cpp

CMakeFiles/testEventlog.dir/src/common/Common.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testEventlog.dir/src/common/Common.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/e823551/Documents/TDDCPP/src/common/Common.cpp > CMakeFiles/testEventlog.dir/src/common/Common.cpp.i

CMakeFiles/testEventlog.dir/src/common/Common.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testEventlog.dir/src/common/Common.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/e823551/Documents/TDDCPP/src/common/Common.cpp -o CMakeFiles/testEventlog.dir/src/common/Common.cpp.s

# Object files for target testEventlog
testEventlog_OBJECTS = \
"CMakeFiles/testEventlog.dir/src/eventlog/Eventlog.cpp.o" \
"CMakeFiles/testEventlog.dir/src/eventlog/eventlogTest.cpp.o" \
"CMakeFiles/testEventlog.dir/src/common/Common.cpp.o"

# External object files for target testEventlog
testEventlog_EXTERNAL_OBJECTS =

testEventlog: CMakeFiles/testEventlog.dir/src/eventlog/Eventlog.cpp.o
testEventlog: CMakeFiles/testEventlog.dir/src/eventlog/eventlogTest.cpp.o
testEventlog: CMakeFiles/testEventlog.dir/src/common/Common.cpp.o
testEventlog: CMakeFiles/testEventlog.dir/build.make
testEventlog: CMakeFiles/testEventlog.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/e823551/Documents/TDDCPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable testEventlog"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testEventlog.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testEventlog.dir/build: testEventlog

.PHONY : CMakeFiles/testEventlog.dir/build

CMakeFiles/testEventlog.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testEventlog.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testEventlog.dir/clean

CMakeFiles/testEventlog.dir/depend:
	cd /Users/e823551/Documents/TDDCPP/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/e823551/Documents/TDDCPP /Users/e823551/Documents/TDDCPP /Users/e823551/Documents/TDDCPP/build /Users/e823551/Documents/TDDCPP/build /Users/e823551/Documents/TDDCPP/build/CMakeFiles/testEventlog.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testEventlog.dir/depend

