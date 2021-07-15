#include "CurlHttp.h"
#include <string>

std::string CurlHttp::m_response;

CurlHttp::CurlHttp() : curl(nullptr)
{}

CurlHttp::~CurlHttp()
{
    curl_global_cleanup();
}

void CurlHttp::initialize()
{
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &CurlHttp::writeCallBack);
}

std::string CurlHttp::get(const std::string& url) const
{
    m_response = "invalid request"; //TODO test
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    return CurlHttp::Response();
}

std::string CurlHttp::Response()
{
    return m_response;
}

size_t CurlHttp::writeCallBack(const char* buf, size_t size, size_t nMemb, void*)
{
    for(auto i = 0u; i < size * nMemb; ++i){
        m_response.push_back(buf[i]);
    }
    return size * nMemb;
}
