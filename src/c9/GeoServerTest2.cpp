#include "CppUTest/TestHarness.h"
#include "CppUTestExtensions.h"
#include "GeoServer.h"
#include "User.h"
#include "VectorUtil.h"
#include "TestTimer.h"
#include "ThreadPool.h"


class GeoServerUsersInBoxTests: public Utest
{
public:
    GeoServer server;

    const double TenMeters {10};
    const double Width {2000 + TenMeters};
    const double Height {4000 + TenMeters};
    const std::string aUser{ "auser" };
    const std::string bUser{ "buser" };
    const std::string cUser{ "cuser" };

    Location aUserLocation{38, -103};

    std::shared_ptr<ThreadPool> pool;

    virtual void setup() override
    {
        server.useThreadPool(pool);
        
        server.track(aUser);
        server.track(bUser);
        server.track(cUser);
        server.updateLocation(aUser, aUserLocation);
    }

    void addUsersAt(unsigned int number, const Location& location)
    {
        for(unsigned int i = 0; i < number; ++i){
            std::string user{"user" + std::to_string(i)};
            server.track(user);
            server.updateLocation(user, location);
        }
    }
};

TEST_GROUP_BASE(AGeoServer_UsersInBox, GeoServerUsersInBoxTests)
{
    class GeoServerUserTrackingListener : public GeoServerListener
    {
    public:
        void updated(const User& user){Users.emplace_back(user);};
        std::vector<User> Users;
    }trackingListener;

    class SingleThreadedPool : public ThreadPool
    {
    public:
        virtual void add(Work work) override {work.execute();}
    };

    void setup() override
    {
        pool = std::make_shared<SingleThreadedPool>();
        GeoServerUsersInBoxTests::setup();
    }

    std::vector<std::string> UserNames(const std::vector<User>& users)
    {
        return Collect<User, std::string>(users, [](User each){return each.name();});
    }
};

TEST(AGeoServer_UsersInBox, AnswersUsersInSpecificedRange)
{
    pool->start(0);
    server.updateLocation(bUser, Location{aUserLocation.go(Width/2 - TenMeters, East)});
    
    server.usersInBox(aUser, Width, Height, &trackingListener);
    CHECK_EQUAL(std::vector<std::string>{bUser}, UserNames(trackingListener.Users));
}

TEST(AGeoServer_UsersInBox, AnswersOnlyUsersWithinSpecifiedRange)
{
    pool->start(0);
    server.updateLocation(bUser, Location{aUserLocation.go(Width/2 + TenMeters, East)});
    server.updateLocation(cUser, Location{aUserLocation.go(Width/2 - TenMeters, East)});
    
    server.usersInBox(aUser, Width, Height, &trackingListener);
    CHECK_EQUAL(std::vector<std::string>{cUser}, UserNames(trackingListener.Users));
}

TEST(AGeoServer_UsersInBox, HandlesLargeNumberOfUsers)
{
    pool->start(0);
    Location anotherLocation{aUserLocation.go(10, West)};
    const unsigned int lots{5000};
    for(unsigned int i{0}; i < lots; ++i){
        std::string user{"user"+std::to_string(i)};
        server.track(user);
        server.updateLocation(user, anotherLocation);
    }

    TestTimer timer;

    server.usersInBox(aUser, Width, Height, &trackingListener);
    CHECK_EQUAL(lots, trackingListener.Users.size());
}

TEST_GROUP_BASE(AGeoServer_ScaleTests, GeoServerUsersInBoxTests)
{
    class GeoServerCountingListener : public GeoServerListener
    {
    public:
        void updated(const User& user) override
        {
            std::unique_lock<std::mutex> lock(mutex_);
            ++Count;
            wasExecuted_.notify_all();
        }

        void waitForCountAndFailOnTimeout(unsigned int expectedCount,
            const std::chrono::microseconds& time=std::chrono::microseconds(10000))
        {
            std::unique_lock<std::mutex> lock(mutex_);
            CHECK_TRUE(wasExecuted_.wait_for(lock, time, 
                [&]{return expectedCount == Count;}));
        }

        std::condition_variable wasExecuted_;
        unsigned int Count{0};
        std::mutex mutex_;
    }countingListenser;

    std::shared_ptr<std::thread> t;

    void setup() override
    {
        pool = std::make_shared<ThreadPool>();
        GeoServerUsersInBoxTests::setup();
    }

    void teardown() override
    {
        t->join();
    }
};

TEST(AGeoServer_ScaleTests, HandlesLargeNumbersOfUsers)
{
    // pool->start(4);
    // const unsigned int lots{5000};
    // addUsersAt(lots, Location{aUserLocation.go(TenMeters, West)});

    // t = std::make_shared<std::thread>(
    //     [&]{server.usersInBox(aUser, Width, Height, &countingListenser);
    // });

    // countingListenser.waitForCountAndFailOnTimeout(lots);
}
