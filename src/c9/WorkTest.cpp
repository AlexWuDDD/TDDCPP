#include "CppUTest/TestHarness.h"
#include "Work.h"
#include <functional>
#include <vector>
#include <sstream>


TEST_GROUP(AWorkObject)
{};

TEST(AWorkObject, DefaultsFunctionToNullObject)
{
    Work work;
    try{
        work.execute();
    }
    catch(...){
        FAIL("unable to execute function");
    }
}

TEST(AWorkObject, DefaultsFunctionToNullObjectWhenConstructedWithId)
{
    Work work(1);
    try{
        work.execute();
    }
    catch(...){
        FAIL("unable to execute function");
    }
}

TEST(AWorkObject, CanBeConstructedWithAnId)
{
    Work work(1);
    LONGS_EQUAL(1, work.id());
}

TEST(AWorkObject, DefaultsIdTo0)
{
    Work work;
    LONGS_EQUAL(0, work.id());
}

TEST(AWorkObject, DefaultsId0WhenFunctionSpecified)
{
    Work work([]{});
    LONGS_EQUAL(0, work.id());
}

TEST(AWorkObject, CanBeConstructedWithAFunctionandId)
{
    Work work([]{}, 1);
    LONGS_EQUAL(1, work.id());
}

TEST(AWorkObject, ExecutesFunctionStored)
{
    bool wasExecuted{false};
    auto executeFunction = [&]{ wasExecuted = true; };
    Work work(executeFunction);
    work.execute();
    CHECK_TRUE(wasExecuted);
}

TEST(AWorkObject, CanExecuteOnDataCapturedWithFunction)
{
    std::vector<std::string> data{"a", "b"};
    std::string result;
    auto callbackFunction = [&](std::string s){result.append(s);};
    auto executeFunction = [&](){
        std::stringstream s;
        s << data[0] << data[1];
        callbackFunction(s.str());
    };
    Work work(executeFunction);
    work.execute();
    CHECK_EQUAL("ab", result);
}