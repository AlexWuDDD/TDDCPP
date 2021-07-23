#include "CppUTest/TestHarness.h"
#include "CppUTestExtensions.h"
#include "GeoServer.h"

TEST_GROUP(AGeoServer)
{
    GeoServer server;

    const std::string aUser{ "auser" };
    
    const double LocationTolearnce{0.005};
};

TEST(AGeoServer, TracksAUser)
{
    server.track(aUser);
    CHECK_TRUE(server.isTracking(aUser));
}

TEST(AGeoServer, IsNotTrackingAUserNotTracked)
{
    CHECK_FALSE(server.isTracking(aUser));
}

TEST(AGeoServer, TracksMultipleUsers)
{
    server.track(aUser);
    server.track("anotheruser");

    CHECK_FALSE(server.isTracking("thirduser"));
    CHECK_TRUE(server.isTracking(aUser));
    CHECK_TRUE(server.isTracking("anotheruser"));
}

TEST(AGeoServer, IsTrackingAnswersFalseWhenUserNoLongerTracked)
{
    server.track(aUser);
    server.stopTracking(aUser);

    CHECK_FALSE(server.isTracking(aUser));
}

TEST(AGeoServer, UpdateLocationOfUser)
{
    server.track(aUser);
    server.updateLocation(aUser, Location{38, -104});

    auto location = server.locationOf(aUser);
    DOUBLES_EQUAL(38, location.latitude(), LocationTolearnce);
    DOUBLES_EQUAL(-104, location.longitude(), LocationTolearnce);
}

TEST(AGeoServer, AnswerUnknownLocationForUserNotTracked)
{
    CHECK_TRUE(server.locationOf("anAbUser").isUnknown());
}

TEST(AGeoServer, AnswerUnknownLocationForTrackedUserWithNoLocationUpdate)
{
    server.track(aUser);
    CHECK_TRUE(server.locationOf(aUser).isUnknown());
}

TEST(AGeoServer, AnswerUnknownLocationForUserNoLongerTracked)
{
    server.track(aUser);
    server.updateLocation(aUser, Location{40, 100});
    server.stopTracking(aUser);
    CHECK_TRUE(server.locationOf(aUser).isUnknown());
}