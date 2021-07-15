#include "PlaceDescriptionService.h"
#include "Http.h"
#include "AddressExtractor.h"
#include "Address.h"
#include "CurlHttp.h"
#include <string>

PlaceDescriptionService::PlaceDescriptionService(std::shared_ptr<HttpFactory> httpFactory)
    : m_httpFactory{httpFactory}
{}

std::string PlaceDescriptionService::summaryDescription(
    const std::string& latitude, const std::string& longitude) const
{
    auto requestUrl = createGetRequestUrl(latitude, longitude);
    auto response = get(requestUrl);
    return summaryDescription(response);
}

std::string PlaceDescriptionService::summaryDescription(const std::string& response) const
{
    AddressExtractor extractor;
    auto address = extractor.addressFrom(response);
    return summaryDescription(address);
}

std::string PlaceDescriptionService::summaryDescription(const Address& address) const
{
    return address.road + ", " + address.city + ", " +
        address.state + ", " + address.country;
}

std::string PlaceDescriptionService::get(const std::string& url) const
{
    auto http = m_httpFactory->get();
    http->initialize();
    return http->get(url);
}

std::string PlaceDescriptionService::createGetRequestUrl(
      const std::string& latitude, const std::string& longitude) const {
   std::string server{"http://open.mapquestapi.com/"};
   std::string document{"nominatim/v1/reverse"};
   return server + document + "?" +
          keyValue("format", "json") + "&" +
          keyValue("lat", latitude) + "&" +
          keyValue("lon", longitude);
}

std::string PlaceDescriptionService::keyValue(
      const std::string& key, const std::string& value) const {
   return key + "=" + value;
}