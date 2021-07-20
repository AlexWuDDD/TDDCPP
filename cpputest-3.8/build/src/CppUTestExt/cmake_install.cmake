# Install script for directory: /Users/e823551/Documents/TDDCPP/cpputest-3.8/src/CppUTestExt

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/CppUTestExt" TYPE FILE FILES
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTestExt/CodeMemoryReportFormatter.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTestExt/IEEE754ExceptionsPlugin.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTestExt/MemoryReportAllocator.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTestExt/MockExpectedCall.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTestExt/MockCheckedExpectedCall.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTestExt/MockExpectedCallsList.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTestExt/MockSupportPlugin.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTestExt/MemoryReportFormatter.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTestExt/MockFailure.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTestExt/MockSupport.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTestExt/MockSupport_c.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTestExt/GMock.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTestExt/GTest.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTestExt/MemoryReporterPlugin.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTestExt/OrderedTest.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTestExt/GTestConvertor.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTestExt/MockActualCall.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTestExt/MockCheckedActualCall.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTestExt/MockNamedValue.h"
    "/Users/e823551/Documents/TDDCPP/cpputest-3.8/include/CppUTestExt/MockSupport.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/e823551/Documents/TDDCPP/cpputest-3.8/build/src/CppUTestExt/libCppUTestExt.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCppUTestExt.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCppUTestExt.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCppUTestExt.a")
  endif()
endif()

