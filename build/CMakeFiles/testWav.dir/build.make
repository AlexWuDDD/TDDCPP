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
include CMakeFiles/testWav.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testWav.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testWav.dir/flags.make

CMakeFiles/testWav.dir/src/c7/wav/testMain.cpp.o: CMakeFiles/testWav.dir/flags.make
CMakeFiles/testWav.dir/src/c7/wav/testMain.cpp.o: ../src/c7/wav/testMain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/e823551/Documents/TDDCPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testWav.dir/src/c7/wav/testMain.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testWav.dir/src/c7/wav/testMain.cpp.o -c /Users/e823551/Documents/TDDCPP/src/c7/wav/testMain.cpp

CMakeFiles/testWav.dir/src/c7/wav/testMain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testWav.dir/src/c7/wav/testMain.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/e823551/Documents/TDDCPP/src/c7/wav/testMain.cpp > CMakeFiles/testWav.dir/src/c7/wav/testMain.cpp.i

CMakeFiles/testWav.dir/src/c7/wav/testMain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testWav.dir/src/c7/wav/testMain.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/e823551/Documents/TDDCPP/src/c7/wav/testMain.cpp -o CMakeFiles/testWav.dir/src/c7/wav/testMain.cpp.s

CMakeFiles/testWav.dir/src/c7/wav/WavReaderTest.cpp.o: CMakeFiles/testWav.dir/flags.make
CMakeFiles/testWav.dir/src/c7/wav/WavReaderTest.cpp.o: ../src/c7/wav/WavReaderTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/e823551/Documents/TDDCPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/testWav.dir/src/c7/wav/WavReaderTest.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testWav.dir/src/c7/wav/WavReaderTest.cpp.o -c /Users/e823551/Documents/TDDCPP/src/c7/wav/WavReaderTest.cpp

CMakeFiles/testWav.dir/src/c7/wav/WavReaderTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testWav.dir/src/c7/wav/WavReaderTest.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/e823551/Documents/TDDCPP/src/c7/wav/WavReaderTest.cpp > CMakeFiles/testWav.dir/src/c7/wav/WavReaderTest.cpp.i

CMakeFiles/testWav.dir/src/c7/wav/WavReaderTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testWav.dir/src/c7/wav/WavReaderTest.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/e823551/Documents/TDDCPP/src/c7/wav/WavReaderTest.cpp -o CMakeFiles/testWav.dir/src/c7/wav/WavReaderTest.cpp.s

CMakeFiles/testWav.dir/src/c7/wav/WavReader.cpp.o: CMakeFiles/testWav.dir/flags.make
CMakeFiles/testWav.dir/src/c7/wav/WavReader.cpp.o: ../src/c7/wav/WavReader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/e823551/Documents/TDDCPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/testWav.dir/src/c7/wav/WavReader.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testWav.dir/src/c7/wav/WavReader.cpp.o -c /Users/e823551/Documents/TDDCPP/src/c7/wav/WavReader.cpp

CMakeFiles/testWav.dir/src/c7/wav/WavReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testWav.dir/src/c7/wav/WavReader.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/e823551/Documents/TDDCPP/src/c7/wav/WavReader.cpp > CMakeFiles/testWav.dir/src/c7/wav/WavReader.cpp.i

CMakeFiles/testWav.dir/src/c7/wav/WavReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testWav.dir/src/c7/wav/WavReader.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/e823551/Documents/TDDCPP/src/c7/wav/WavReader.cpp -o CMakeFiles/testWav.dir/src/c7/wav/WavReader.cpp.s

CMakeFiles/testWav.dir/src/c7/wav/WavDescriptor.cpp.o: CMakeFiles/testWav.dir/flags.make
CMakeFiles/testWav.dir/src/c7/wav/WavDescriptor.cpp.o: ../src/c7/wav/WavDescriptor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/e823551/Documents/TDDCPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/testWav.dir/src/c7/wav/WavDescriptor.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testWav.dir/src/c7/wav/WavDescriptor.cpp.o -c /Users/e823551/Documents/TDDCPP/src/c7/wav/WavDescriptor.cpp

CMakeFiles/testWav.dir/src/c7/wav/WavDescriptor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testWav.dir/src/c7/wav/WavDescriptor.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/e823551/Documents/TDDCPP/src/c7/wav/WavDescriptor.cpp > CMakeFiles/testWav.dir/src/c7/wav/WavDescriptor.cpp.i

CMakeFiles/testWav.dir/src/c7/wav/WavDescriptor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testWav.dir/src/c7/wav/WavDescriptor.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/e823551/Documents/TDDCPP/src/c7/wav/WavDescriptor.cpp -o CMakeFiles/testWav.dir/src/c7/wav/WavDescriptor.cpp.s

CMakeFiles/testWav.dir/src/common/Common.cpp.o: CMakeFiles/testWav.dir/flags.make
CMakeFiles/testWav.dir/src/common/Common.cpp.o: ../src/common/Common.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/e823551/Documents/TDDCPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/testWav.dir/src/common/Common.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testWav.dir/src/common/Common.cpp.o -c /Users/e823551/Documents/TDDCPP/src/common/Common.cpp

CMakeFiles/testWav.dir/src/common/Common.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testWav.dir/src/common/Common.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/e823551/Documents/TDDCPP/src/common/Common.cpp > CMakeFiles/testWav.dir/src/common/Common.cpp.i

CMakeFiles/testWav.dir/src/common/Common.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testWav.dir/src/common/Common.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/e823551/Documents/TDDCPP/src/common/Common.cpp -o CMakeFiles/testWav.dir/src/common/Common.cpp.s

CMakeFiles/testWav.dir/src/eventlog/Eventlog.cpp.o: CMakeFiles/testWav.dir/flags.make
CMakeFiles/testWav.dir/src/eventlog/Eventlog.cpp.o: ../src/eventlog/Eventlog.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/e823551/Documents/TDDCPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/testWav.dir/src/eventlog/Eventlog.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testWav.dir/src/eventlog/Eventlog.cpp.o -c /Users/e823551/Documents/TDDCPP/src/eventlog/Eventlog.cpp

CMakeFiles/testWav.dir/src/eventlog/Eventlog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testWav.dir/src/eventlog/Eventlog.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/e823551/Documents/TDDCPP/src/eventlog/Eventlog.cpp > CMakeFiles/testWav.dir/src/eventlog/Eventlog.cpp.i

CMakeFiles/testWav.dir/src/eventlog/Eventlog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testWav.dir/src/eventlog/Eventlog.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/e823551/Documents/TDDCPP/src/eventlog/Eventlog.cpp -o CMakeFiles/testWav.dir/src/eventlog/Eventlog.cpp.s

# Object files for target testWav
testWav_OBJECTS = \
"CMakeFiles/testWav.dir/src/c7/wav/testMain.cpp.o" \
"CMakeFiles/testWav.dir/src/c7/wav/WavReaderTest.cpp.o" \
"CMakeFiles/testWav.dir/src/c7/wav/WavReader.cpp.o" \
"CMakeFiles/testWav.dir/src/c7/wav/WavDescriptor.cpp.o" \
"CMakeFiles/testWav.dir/src/common/Common.cpp.o" \
"CMakeFiles/testWav.dir/src/eventlog/Eventlog.cpp.o"

# External object files for target testWav
testWav_EXTERNAL_OBJECTS =

testWav: CMakeFiles/testWav.dir/src/c7/wav/testMain.cpp.o
testWav: CMakeFiles/testWav.dir/src/c7/wav/WavReaderTest.cpp.o
testWav: CMakeFiles/testWav.dir/src/c7/wav/WavReader.cpp.o
testWav: CMakeFiles/testWav.dir/src/c7/wav/WavDescriptor.cpp.o
testWav: CMakeFiles/testWav.dir/src/common/Common.cpp.o
testWav: CMakeFiles/testWav.dir/src/eventlog/Eventlog.cpp.o
testWav: CMakeFiles/testWav.dir/build.make
testWav: CMakeFiles/testWav.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/e823551/Documents/TDDCPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable testWav"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testWav.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testWav.dir/build: testWav

.PHONY : CMakeFiles/testWav.dir/build

CMakeFiles/testWav.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testWav.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testWav.dir/clean

CMakeFiles/testWav.dir/depend:
	cd /Users/e823551/Documents/TDDCPP/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/e823551/Documents/TDDCPP /Users/e823551/Documents/TDDCPP /Users/e823551/Documents/TDDCPP/build /Users/e823551/Documents/TDDCPP/build /Users/e823551/Documents/TDDCPP/build/CMakeFiles/testWav.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testWav.dir/depend

