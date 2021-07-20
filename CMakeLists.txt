cmake_minimum_required(VERSION 3.5)

project(TDDCPP)

set(CMAKE_CXX_STANDARD 11)

set(GTEST_INC_DIR ${PROJECT_SOURCE_DIR}/googletest-release-1.11.0/googletest/include)
set(GMOCK_INC_DIR ${PROJECT_SOURCE_DIR}/googletest-release-1.11.0/googlemock/include)
set(JSONCPP_INC_DIR ${PROJECT_SOURCE_DIR}/jsoncpp-1.9.4/include)
set(CURL_INC_DIR ${PROJECT_SOURCE_DIR}/curl-7.77.0/inclide)
set(BOOST_INC_DIR ${PROJECT_SOURCE_DIR}/boost_1_76_0)
set(RLOG_INC_DIR ${PROJECT_SOURCE_DIR}/rlog-1.4/rlog)
set(CPPUTEST_INC_DIR ${PROJECT_SOURCE_DIR}/cpputest-3.8/include)

set(GTESTGMOCK_LIB_DIR ${PROJECT_SOURCE_DIR}/googletest-release-1.11.0/build/lib)
set(JSONCPP_LIB_DIR ${PROJECT_SOURCE_DIR}/jsoncpp-1.9.4/build/lib)
set(CURL_LIB_DIR ${PROJECT_SOURCE_DIR}/curl-7.77.0/lib/.libs)
set(RLOG_LIB_DIR ${PROJECT_SOURCE_DIR}/rlog-1.4/rlog/.libs)
set(CPPUTEST_LIB_DIR ${PROJECT_SOURCE_DIR}/cpputest-3.8/build/src/CppUTest)
set(CPPUTESTEXT_LIB_DIR ${PROJECT_SOURCE_DIR}/cpputest-3.8/build/src/CppUTestExt)


include_directories(
    ${GTEST_INC_DIR} 
    ${GMOCK_INC_DIR} 
    ${JSONCPP_INC_DIR}
    ${CURL_INC_DIR}
    ${BOOST_INC_DIR}
    ${RLOG_INC_DIR}
    ${CPPUTEST_INC_DIR}
)
link_directories(
    ${GTESTGMOCK_LIB_DIR} 
    ${JSONCPP_LIB_DIR}
    ${CURL_LIB_DIR}
    ${RLOG_LIB_DIR}
    ${CPPUTEST_LIB_DIR}
    ${CPPUTESTEXT_LIB_DIR}
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