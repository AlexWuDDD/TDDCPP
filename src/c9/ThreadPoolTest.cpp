#include "CppUTest/TestHarness.h"
#include "ThreadPool.h"
#include <vector>
#include <set>

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

class ThreadPoolThreadTests : public Utest
{
public:
    ThreadPool pool;
    std::mutex m;
    std::condition_variable wasExecuted;
    unsigned int count{0};
    std::vector<std::shared_ptr<std::thread>> threads;

    void teardown() override
    {
        for(auto& t : threads) t->join();
    }

    void incrementCountAndNotify()
    {
        std::unique_lock<std::mutex> lock(m);
        ++count;
        wasExecuted.notify_all();
    }

    void waitForCountAndFailOnTimeout(
        unsigned int expectedCount,
        const std::chrono::milliseconds& time = std::chrono::milliseconds(500)
    )
    {
        std::unique_lock<std::mutex> lock(m);
        CHECK_TRUE(wasExecuted.wait_for(lock, time,
            [&]{return count == expectedCount;}));
    }
};

TEST_GROUP_BASE(AThreadPool_AddRequest, ThreadPoolThreadTests)
{   
    void setup() override
    {
        pool.start();
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

TEST(AThreadPool_AddRequest, HoldsUpUnderClientStress)
{
    Work work{[&]{incrementCountAndNotify();}};
    unsigned int NumOfWorkItems{10};
    unsigned int NumOfThreads{10};
    for(unsigned int i{0}; i < NumOfThreads; ++i){
        threads.push_back(std::make_shared<std::thread>(
            [&]{
                for(unsigned int j{0}; j < NumOfWorkItems; ++j){
                    pool.add(work);
                }
            }
        ));
    }
    waitForCountAndFailOnTimeout(NumOfThreads * NumOfWorkItems);
}


TEST_GROUP_BASE(AThreadPoolWithMultipleThreads, ThreadPoolThreadTests)
{
    std::set<std::thread::id> threads;
    void addThreadIfUnique(const std::thread::id& id){
        std::unique_lock<std::mutex> lock(m);
        threads.insert(id);
    }

    size_t numberOfThreadsProcessed()
    {
        return threads.size();
    }
};

TEST(AThreadPoolWithMultipleThreads, DispatchesWorkToMultipleThreads)
{
    unsigned int numberOfThreads{2};
    pool.start(numberOfThreads);
    Work work{[&]{
        addThreadIfUnique(std::this_thread::get_id());
        incrementCountAndNotify();
    }};
    unsigned int NumOfWorkItems{500};
    for(unsigned int i{0}; i < NumOfWorkItems; ++i){
        pool.add(work);
    }

    waitForCountAndFailOnTimeout(NumOfWorkItems);
    LONGS_EQUAL(numberOfThreads, numberOfThreadsProcessed());
}
