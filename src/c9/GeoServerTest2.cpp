#include "CppUTest/TestHarness.h"
#include "CppUTestExtensions.h"
#include "GeoServer.h"
#include "User.h"
#include "VectorUtil.h"
#include "TestTimer.h"

TEST_GROUP(AGeoServer_UsersInBox)
{
    GeoServer server;

    const double TenMeters {10};
    const double Width {2000 + TenMeters};
    const double Height {4000 + TenMeters};
    const std::string aUser{ "auser" };
    const std::string bUser{ "buser" };
    const std::string cUser{ "cuser" };
    
    Location aUserLocation{38, -103};

    void setup() override
    {
        server.track(aUser);
        server.track(bUser);
        server.track(cUser);
        server.updateLocation(aUser, aUserLocation);
    }

    std::vector<std::string> UserNames(const std::vector<User>& users)
    {
        return Collect<User, std::string>(users, [](User each){return each.name();});
    }
};

TEST(AGeoServer_UsersInBox, AnswersUsersInSpecificedRange)
{
    server.updateLocation(bUser, Location{aUserLocation.go(Width/2 - TenMeters, East)});
    
    auto users = server.usersInBox(aUser, Width, Height);
    CHECK_EQUAL(std::vector<std::string>{bUser}, UserNames(users));
}

TEST(AGeoServer_UsersInBox, AnswersUsersInSpecificedRang)
{
    server.updateLocation(bUser, Location{aUserLocation.go(Width/2 + TenMeters, East)});
    server.updateLocation(cUser, Location{aUserLocation.go(Width/2 - TenMeters, East)});
    
    auto users = server.usersInBox(aUser, Width, Height);
    CHECK_EQUAL(std::vector<std::string>{cUser}, UserNames(users));
}

TEST(AGeoServer_UsersInBox, HandlesLargeNumberOfUsers)
{
    Location anotherLocation{aUserLocation.go(10, West)};
    const unsigned int lots{50000};
    for(unsigned int i{0}; i < lots; ++i){
        std::string user{"user"+std::to_string(i)};
        server.track(user);
        server.updateLocation(user, anotherLocation);
    }

    TestTimer timer;

    auto users = server.usersInBox(aUser, Width, Height);
    CHECK_EQUAL(lots, users.size());
}
