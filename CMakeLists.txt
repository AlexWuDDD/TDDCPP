cmake_minimum_required(VERSION 3.5)

project(TDDCPP)

set(CMAKE_CXX_STANDARD 11)

set(GTEST_INC_DIR ${PROJECT_SOURCE_DIR}/googletest-release-1.11.0/googletest/include)
set(GMOCK_INC_DIR ${PROJECT_SOURCE_DIR}/googletest-release-1.11.0/googlemock/include)
set(JSONCPP_INC_DIR ${PROJECT_SOURCE_DIR}/jsoncpp-1.9.4/include)
set(CURL_INC_DIR ${PROJECT_SOURCE_DIR}/curl-7.77.0/inclide)
set(BOOST_INC_DIR ${PROJECT_SOURCE_DIR}/boost_1_76_0)
set(CPPUTEST_INC_DIR ${PROJECT_SOURCE_DIR}/cpputest-3.8/include)
set(GLOG_INC_DIR ${PROJECT_SOURCE_DIR}/glog-0.5.0/install/include)

set(COMMON_INC_DIR ${PROJECT_SOURCE_DIR}/src/common)
set(EVENTLOG_INC_DIR ${PROJECT_SOURCE_DIR}/src/eventlog)

set(utilSRCS ${PROJECT_SOURCE_DIR}/src/common/Common.cpp ${PROJECT_SOURCE_DIR}/src/eventlog/EventLog.cpp)

set(GTESTGMOCK_LIB_DIR ${PROJECT_SOURCE_DIR}/googletest-release-1.11.0/build/lib)
set(JSONCPP_LIB_DIR ${PROJECT_SOURCE_DIR}/jsoncpp-1.9.4/build/lib)
set(CURL_LIB_DIR ${PROJECT_SOURCE_DIR}/curl-7.77.0/lib/.libs)
set(CPPUTEST_LIB_DIR ${PROJECT_SOURCE_DIR}/cpputest-3.8/build/src/CppUTest)
set(CPPUTESTEXT_LIB_DIR ${PROJECT_SOURCE_DIR}/cpputest-3.8/build/src/CppUTestExt)
set(BOOST_LIB_DIR ${PROJECT_SOURCE_DIR}/boost_1_76_0/stage/lib)
set(GLOG_LIN_DIR ${PROJECT_SOURCE_DIR}/glog-0.5.0/install/lib)


include_directories(
    ${GTEST_INC_DIR} 
    ${GMOCK_INC_DIR} 
    ${JSONCPP_INC_DIR}
    ${CURL_INC_DIR}
    ${BOOST_INC_DIR}
    ${CPPUTEST_INC_DIR}
    ${GLOG_INC_DIR}
    ${COMMON_INC_DIR}
    ${EVENTLOG_INC_DIR}
)
link_directories(
    ${GTESTGMOCK_LIB_DIR} 
    ${JSONCPP_LIB_DIR}
    ${CURL_LIB_DIR}
    ${CPPUTEST_LIB_DIR}
    ${CPPUTESTEXT_LIB_DIR}
    ${BOOST_LIB_DIR}
    ${GLOG_LIN_DIR}
)

add_executable(testMain 
    src/c2/1/main.cpp 
    src/c2/1/SoundexTest.cpp 
    src/Soundex/Soundex.cpp 
    src/utilities/StringUtil.cpp src/utilities/CharUtil.cpp)
target_link_libraries(testMain gmock_main gmock gtest_main gtest pthread)

add_executable(testMain2
    src/c3/1/main.cpp
    src/c3/1/RetweetCollectionTest.cpp
    src/c3/1/RetweetCollectionWithOneTweetTest.cpp
    src/RetweetCollection/RetweetCollection.cpp
    src/Tweet/Tweet.cpp
)
target_link_libraries(testMain2 gmock_main gmock gtest_main gtest pthread)

add_executable(testDouble
    src/c5/1/main.cpp
    src/c5/1/Http.h
    src/c5/1/PlaceDescriptionServiceTest.cpp
    src/c5/1/PlaceDescriptionService.cpp
    src/c5/1/AddressExtractor.cpp
)
target_link_libraries(testDouble gmock_main gmock gtest_main gtest pthread jsoncpp_static)

add_executable(testMock
    src/c5/7/main.cpp
    src/c5/7/PlaceDescriptionServiceTest.cpp
    src/c5/7/PlaceDescriptionService.cpp
    src/c5/7/AddressExtractor.cpp
)
target_link_libraries(testMock gmock_main gmock gtest_main gtest pthread jsoncpp_static)

add_executable(testMock2
    src/c5/13/main.cpp
    src/c5/13/OutParameterTest.cpp
)
target_link_libraries(testMock2 gmock_main gmock gtest_main gtest pthread)

add_executable(testMock3
    src/c5/15/PlaceDescriptionServiceTest.cpp
    src/c5/15/main.cpp
    src/c5/15/AddressExtractor.cpp
    src/c5/15/CurlHttp.cpp
    src/c5/15/PlaceDescriptionService.cpp
    src/c5/15/HttpFactory.cpp
    )
target_link_libraries(testMock3 gmock_main gmock gtest_main gtest pthread jsoncpp_static curl)

add_executable(testSimpleDesign
    src/c6/1/main.cpp
    src/c6/1/PortfolioTest.cpp
    src/c6/1/portfolio.cpp
)
target_link_libraries(testSimpleDesign gmock_main gmock gtest_main gtest pthread)

add_executable(testFileRead 
    src/c7/wav/testFileRead.cpp
)

add_executable(testEventlog
    src/eventlog/Eventlog.cpp
    src/eventlog/eventlogTest.cpp
    ${utilSRCS}
)
target_link_libraries(testEventlog glog)

add_executable(testWav
    src/c7/wav/testMain.cpp
    src/c7/wav/WavReaderTest.cpp
    src/c7/wav/WavReader.cpp
    src/c7/wav/WavDescriptor.cpp
    ${utilSRCS}
)
target_link_libraries(testWav pthread  gtest boost_filesystem glog)

add_executable(testThread
    src/c9/testMain.cpp
    src/c9/CppUTestExtensionsTest.cpp
    src/c9/CppUTestExtensions.cpp

    src/c9/Area.cpp
    src/c9/Location.cpp
    src/c9/GeoServer.cpp
    src/c9/GeoServerTest.cpp
    src/c9/GeoServerTest2.cpp
    src/c9/TestTimer.cpp

    src/c9/WorkTest.cpp
    src/c9/ThreadPoolTest.cpp
)
target_link_libraries(testThread pthread CppUTest)