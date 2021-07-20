# Install script for directory: /Users/e823551/Documents/TDDCPP/cpputest-3.8/src/CppUTest

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/CppUTest" TYPE FILE FILES
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTest/CommandLineArguments.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTest/PlatformSpecificFunctions.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTest/TestMemoryAllocator.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTest/CommandLineTestRunner.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTest/PlatformSpecificFunctions_c.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTest/TestOutput.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTest/CppUTestConfig.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTest/SimpleString.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTest/TestPlugin.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTest/JUnitTestOutput.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTest/TeamCityTestOutput.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTest/StandardCLibrary.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTest/TestRegistry.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTest/MemoryLeakDetector.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTest/TestFailure.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTest/TestResult.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTest/MemoryLeakDetectorMallocMacros.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTest/TestFilter.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTest/TestTestingFixture.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTest/MemoryLeakDetectorNewMacros.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTest/TestHarness.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTest/Utest.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTest/MemoryLeakWarningPlugin.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTest/TestHarness_c.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTest/UtestMacros.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/e823551/Documents/TDDCPP/cpputest-3.8/build/src/CppUTest/libCppUTest.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCppUTest.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCppUTest.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCppUTest.a")
  endif()
endif()

