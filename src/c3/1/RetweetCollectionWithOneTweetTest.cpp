#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../../RetweetCollection/RetweetCollection.h"
#include "../../Tweet/Tweet.h"

using namespace ::testing;

class ARetweetCollectionWithOneTweet: public Test
{
public:
    RetweetCollection collection;
    Tweet* tweet;
    void SetUp() override
    {
        tweet = new Tweet("msg", "@user");
        collection.add(*tweet);
    }

    /*
    It executes after each test, even if the test threw an exception. 
    You use the teardown function for cleanup purposes—to release memory (as in this example), 
    to relinquish expensive resources (for example, database connec- tions), 
    or to clean up other bits of state, such as data stored in static variables.
    */
    void TearDown() override
    {
        delete tweet;
        tweet = nullptr;
    }
};

TEST_F(ARetweetCollectionWithOneTweet, IsNoLongerEmpty)
{
    ASSERT_FALSE(collection.isEmpty());
}

TEST_F(ARetweetCollectionWithOneTweet, HasSizeofOne)
{
    ASSERT_THAT(collection.size(), Eq(1u));
}

TEST_F(ARetweetCollectionWithOneTweet, IgnoresDuplicateTweetAdded)
{
    Tweet duplocale(*tweet);
    collection.add(duplocale);
    
    ASSERT_THAT(collection.size(), Eq(1u));
}

