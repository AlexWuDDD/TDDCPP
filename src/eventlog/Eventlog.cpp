#include "Eventlog.h"
#include "glog/logging.h"

Eventlog& Eventlog::GetInstance(const std::string& logDir)
{
    static Eventlog m_instance(logDir);
    return m_instance;
}

Eventlog::Eventlog(const std::string& logDir)
{
    google::InitGoogleLogging("Eventlog");
    google::SetLogDestination(google::GLOG_INFO, logDir.c_str());
}

Eventlog::~Eventlog()
{
    google::ShutdownGoogleLogging();
}