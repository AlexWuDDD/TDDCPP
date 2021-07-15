#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Http.h"
#include "PlaceDescriptionService.h"

using namespace testing;

class APlaceDescriptionServiceTest : public Test
{
public:
    static std::string ValidLatitude;
    static std::string ValidLongtitude;
};

std::string APlaceDescriptionServiceTest::ValidLatitude = "1";
std::string APlaceDescriptionServiceTest::ValidLongtitude = "2";


class HttpStub : public Http
{
public:
    HttpStub(){}
    ~HttpStub(){}
    void initialize() override {}
    std::string returnResponse;
    std::string expectedURL;
    std::string get(const std::string& url) const override
    {
        verify(url);
        return returnResponse;
    }

    void verify(const std::string& url) const
    {
        ASSERT_THAT(url, Eq(expectedURL));
    }
};


TEST_F(APlaceDescriptionServiceTest, ReturnsDescriptionForValidLocation)
{
    HttpStub httpStub;
    httpStub.returnResponse = R"({ 
            "address":{
                "road": "Drury Ln",
                "city": "Fountain",
                "state": "CO",
                "country": "US"
            }
        })";
    std::string urlStart{
        "http://open.mapquestapi.com/nominatim/v1/reverse?format=json&"};
    httpStub.expectedURL = urlStart + 
        "lat=" + APlaceDescriptionServiceTest::ValidLatitude + "&" + 
        "lon=" + APlaceDescriptionServiceTest::ValidLongtitude;
        
    PlaceDescriptionService service{&httpStub};

    auto description = service.summaryDescription(ValidLatitude, ValidLongtitude);

    ASSERT_THAT(description, Eq("Drury Ln, Fountain, CO, US"));
}