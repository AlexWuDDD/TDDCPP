#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Http.h"
#include "PlaceDescriptionService.h"

using namespace testing;

class HttpStub : public Http
{
public:
    MOCK_METHOD0(initialize, void());
    MOCK_CONST_METHOD1(get, std::string(const std::string&));
};

class APlaceDescriptionService : public Test
{
public:
    static std::string ValidLatitude;
    static std::string ValidLongtitude;
};

std::string APlaceDescriptionService::ValidLatitude = "1";
std::string APlaceDescriptionService::ValidLongtitude = "2";

TEST_F(APlaceDescriptionService,  MakesHttpRequestToObtainAddress)
{
    InSequence forceExpectationOrder;
    HttpStub httpStub;
    std::string urlStart{
        "http://open.mapquestapi.com/nominatim/v1/reverse?format=json&"};
    auto expectedURL = urlStart + 
        "lat=" + APlaceDescriptionService::ValidLatitude + "&" + 
        "lon=" + APlaceDescriptionService::ValidLongtitude;
    EXPECT_CALL(httpStub, initialize());
    EXPECT_CALL(httpStub, get(expectedURL));
    PlaceDescriptionService service{&httpStub};
    service.summaryDescription(ValidLatitude, ValidLongtitude);
}

TEST_F(APlaceDescriptionService, FormatsRetrievedAddressIntoSummaryDescription)
{
    NiceMock<HttpStub> httpStub;
    // HttpStub httpStub;
    // StrictMock<HttpStub> httpStub;

    EXPECT_CALL(httpStub, get(_))
        .WillOnce(Return(
            R"({ 
                "address":{
                    "road": "Drury Ln",
                    "city": "Fountain",
                    "state": "CO",
                    "country": "US"
                }
            })"
        ));
    PlaceDescriptionService service(&httpStub);
    auto Description = service.summaryDescription(ValidLatitude, ValidLongtitude);
    ASSERT_THAT(Description, Eq("Drury Ln, Fountain, CO, US"));
}