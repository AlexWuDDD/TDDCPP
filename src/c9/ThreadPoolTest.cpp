#include "CppUTest/TestHarness.h"
#include "ThreadPool.h"

TEST_GROUP(AThreadPool)
{
    std::mutex m;
    ThreadPool pool;
};

TEST(AThreadPool, HasNoWorkOnCreation)
{
    CHECK_FALSE(pool.hasWork());
}

TEST(AThreadPool, HasWorkAfterAdd)
{
    pool.add(Work{});
    CHECK_TRUE(pool.hasWork());
}

TEST(AThreadPool, AnswerWorkAddedOnPull)
{
    pool.add(Work{1});
    auto work = pool.pullWork();

    LONGS_EQUAL(1, work.id());
}

TEST(AThreadPool, PullsElementsInFIFOOrder)
{
    pool.add(Work{1});
    pool.add(Work{2});

    auto work = pool.pullWork();
    LONGS_EQUAL(1, work.id());
}

TEST(AThreadPool, HasNoWorkAfterLastElementRemoved)
{
    pool.add(Work{});
    pool.pullWork();
    CHECK_FALSE(pool.hasWork());
}

TEST(AThreadPool, HasWorkAfterWorkRemovedButWorkRemains)
{
    pool.add(Work{});
    pool.add(Work{});
    pool.pullWork();
    CHECK_TRUE(pool.hasWork());
}

TEST(AThreadPool, PullsWorkInAThread)
{
    pool.start();
    std::condition_variable wasExecuted;
    bool wasWorked{0};
    Work work{[&]{
        std::unique_lock<std::mutex> lock(m);
        wasWorked = true;
        wasExecuted.notify_all();
    }};

    pool.add(work);
    std::unique_lock<std::mutex> lock(m);
    CHECK_TRUE(wasExecuted.wait_for(lock, std::chrono::milliseconds(100),
        [&]{return wasWorked;}));
}

TEST(AThreadPool, ExecutesAllWork)
{
    pool.start();
    unsigned int count{0};
    unsigned int NumberOfWorkItems{3};

    std::condition_variable wasExecuted;

    Work work{
        [&]{
            std::unique_lock<std::mutex> lock(m);
            ++count;
            wasExecuted.notify_all();
        }
    };
    for (unsigned int i = 0; i < NumberOfWorkItems; ++i){
        pool.add(work);
    } 
    std::unique_lock<std::mutex> lock(m);
    CHECK_TRUE(wasExecuted.wait_for(lock, std::chrono::milliseconds(100),
        [&]{return count == NumberOfWorkItems;}));
}

TEST_GROUP(AThreadPool_AddRequest)
{
    std::mutex m;
    ThreadPool pool;
    std::condition_variable wasExecuted;
    unsigned int count{0};
    
    void setup() override
    {
        pool.start();
    }

    void incrementCountAndNotify()
    {
        std::unique_lock<std::mutex> lock(m);
        ++count;
        wasExecuted.notify_all();
    }

    void waitForCountAndFailOnTimeout(
        unsigned int expectedCount,
        const std::chrono::milliseconds& time = std::chrono::milliseconds(100)
    )
    {
        std::unique_lock<std::mutex> lock(m);
        CHECK_TRUE(wasExecuted.wait_for(lock, time,
            [&]{return count == expectedCount;}));
    }
};

TEST(AThreadPool_AddRequest, PullsWorkInAThread)
{
    Work work{[&]{incrementCountAndNotify();}};
    unsigned int NumOfWorkItems{1};
    pool.add(work);
    waitForCountAndFailOnTimeout(NumOfWorkItems);
}

TEST(AThreadPool_AddRequest, ExecutesAllWork)
{
    Work work{[&]{incrementCountAndNotify();}};
    unsigned int NumOfWorkItems{3};
    for(unsigned int i{0}; i < NumOfWorkItems; ++i){
        pool.add(work);
    }
    waitForCountAndFailOnTimeout(NumOfWorkItems);
}

