#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace testing;

class DifficultColloborator
{
public:
    virtual bool calculate(int* result)
    {
        throw 1;
    }
};

class Target
{
public:
    int execute(DifficultColloborator* calculator)
    {
        int i;
        if(!calculator->calculate(&i))
            return 0;
        return i;
    }
};

class DifficultColloboratorMock : public DifficultColloborator
{
public:
    MOCK_METHOD1(calculate, bool(int*));
};

TEST(ATarget, ReturnsAnAmountWhenCalculatePasses)
{
    DifficultColloboratorMock difficult;
    Target calc;
    EXPECT_CALL(difficult, calculate(_))
        .WillOnce(DoAll(
            SetArgPointee<0>(3),
            Return(true)
        ));
    auto result = calc.execute(&difficult);
    ASSERT_THAT(result, Eq(3));
};