#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "PlaceDescriptionService.h"
#include "Http.h"
#include "HttpFactory.h"

using namespace std;
using namespace testing;

class HttpStub : public Http
{
public:
    MOCK_METHOD0(initialize, void());
    MOCK_CONST_METHOD1(get, string(const string&));
};

class APlaceDescriptionService : public Test
{
public:
    static const string ValidLatitude;
    static const string ValidLongitude;

    shared_ptr<HttpStub> httpStub;
    shared_ptr<HttpFactory> factory;
    shared_ptr<PlaceDescriptionService> service;

    virtual void SetUp() override
    {
        factory = make_shared<HttpFactory>();
        service = make_shared<PlaceDescriptionService>(factory);
    }

    void TearDown() override
    {
        factory.reset();
        httpStub.reset();
    }

};
const string APlaceDescriptionService::ValidLatitude("38.005");
const string APlaceDescriptionService::ValidLongitude("-104.44");

// class PlaceDescriptionService_StubHttpService : public PlaceDescriptionService
// {
// public:
//     PlaceDescriptionService_StubHttpService(shared_ptr<HttpStub> httpStub)
//         : m_httpStub(httpStub){}
//     shared_ptr<Http> httpService() const override {return m_httpStub;}
//     shared_ptr<Http> m_httpStub;
// };

// TEST_F(APlaceDescriptionService, MakesHttpRequestToObtainAddress)
// {
//     InSequence forceExceptionOrder;
//     shared_ptr<HttpStub> httpStub{new HttpStub()};

//     string urlStart{
//       "http://open.mapquestapi.com/nominatim/v1/reverse?format=json&"};
	  
//    auto expectedURL = urlStart + 
//       "lat=" + APlaceDescriptionService::ValidLatitude + "&" +
//       "lon=" + APlaceDescriptionService::ValidLongitude;
//    EXPECT_CALL(*httpStub, initialize());
//    EXPECT_CALL(*httpStub, get(expectedURL));
//    PlaceDescriptionService_StubHttpService service{httpStub};

//     service.summaryDescription(ValidLatitude, ValidLongitude);
// };

class APlaceDescriptionService_WithHttpMock : public APlaceDescriptionService
{
public:
    void SetUp() override
    {
        APlaceDescriptionService::SetUp();
        httpStub = make_shared<HttpStub>();
        factory->setInstance(httpStub);
    }
};

TEST_F(APlaceDescriptionService_WithHttpMock, MakesHttpRequestToObtainAddress) 
{ 
    string urlStart{
        "http://open.mapquestapi.com/nominatim/v1/reverse?format=json&"}; 
    auto expectedURL = urlStart +
        "lat=" + APlaceDescriptionService::ValidLatitude + "&" +
        "lon=" + APlaceDescriptionService::ValidLongitude; 
    EXPECT_CALL(*httpStub, initialize()); 
    EXPECT_CALL(*httpStub, get(expectedURL)); 
    service->summaryDescription(ValidLatitude, ValidLongitude);
}