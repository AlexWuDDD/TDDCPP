#include "PlaceDescriptionService.h"
#include  "AddressExtractor.h"
#include "Http.h"

PlaceDescriptionService::PlaceDescriptionService(Http* http):
    m_http(http)
{

}

PlaceDescriptionService::~PlaceDescriptionService()
{

}

std::string PlaceDescriptionService::summaryDescription(const std::string& latitude, const std::string& longitude) const
{
    auto url = createGetReqestUrl(latitude, longitude);
    auto response = get(url);
    return summaryDescription(response);
}

std::string PlaceDescriptionService::summaryDescription(const std::string& response) const
{
    AddressExtractor extractor;
    auto address = extractor.addressFrom(response);
    return address.road + ", " + address.city + ", " +
        address.state + ", " + address.country;
}

std::string PlaceDescriptionService::get(const std::string& requestUrl) const
{
    // auto response = m_http->get(requestUrl);
    m_http->initialize();
    // return response;
    return m_http->get(requestUrl);
}

std::string PlaceDescriptionService::createGetReqestUrl(const std::string& latitude, const std::string& longitude) const
{
    std::string server{"http://open.mapquestapi.com/"};
    std::string document{"nominatim/v1/reverse"};
    return server + document + "?" + 
        keyValue("format", "json") + "&" + 
        keyValue("lat", latitude) + "&" +
        keyValue("lon", longitude); 
}

std::string PlaceDescriptionService::keyValue(
    const std::string& key, const std::string& value) const
{
    return key + "=" + value;
}