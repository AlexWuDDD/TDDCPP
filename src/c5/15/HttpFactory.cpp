#include "HttpFactory.h"
#include "CurlHttp.h"
#include <memory>

using namespace std;

HttpFactory::HttpFactory()
{
    reset();
}

std::shared_ptr<Http> HttpFactory::get()
{
    return instance;
}

void HttpFactory::reset()
{
    instance = std::make_shared<CurlHttp>();
}

void HttpFactory::setInstance(std::shared_ptr<Http> newInstance)
{
    instance = newInstance;
}