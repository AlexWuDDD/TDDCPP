#ifndef PLACEDESCRIPTIONSERVICE_H
#define PLACEDESCRIPTIONSERVICE_H

#include <string>
class Http;
class PlaceDescriptionService
{
public:
    PlaceDescriptionService(Http* http);
    ~PlaceDescriptionService();

    std::string summaryDescription(const std::string& latitude, const std::string& longitude) const;
    std::string summaryDescription(const std::string& response) const;
    std::string get(const std::string& requestUrl) const;
    std::string createGetReqesyUrl(const std::string& latitude, const std::string& longitude) const;
    std::string keyValue(
        const std::string& key, const std::string& value) const;

private:
    Http *m_http;
};

#endif