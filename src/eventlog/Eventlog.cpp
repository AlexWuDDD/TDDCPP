#include "Eventlog.h"
#include "glog/logging.h"
#include "Common.h"
#include <iostream>

Eventlog& Eventlog::GetInstance()
{
    static Eventlog m_instance;
    return m_instance;
}

Eventlog::Eventlog()
{
    buff = new char[BUFF_SIZE];
    assert(buff != nullptr);
    Common::createDir(LOG_DIR);
    FLAGS_log_dir = LOG_DIR;
    google::InitGoogleLogging("Eventlog");
    // google::SetLogDestination(google::INFO, LOG_FILE_PREFIEX);
    google::SetStderrLogging(google::GLOG_INFO);
    google::EnableLogCleaner(3);

#if OUTPUT_TO_CONSOLE
    FLAGS_alsologtostderr = true;
    FLAGS_colorlogtostderr = true;
#endif
    FLAGS_log_prefix = true;
    FLAGS_logbufsecs = 0;
    FLAGS_max_log_size = EACH_LOG_SIZE; //MB
    
    FLAGS_stop_logging_if_full_disk = true;
    std::cout << "init" << std::endl;
}

Eventlog::~Eventlog()
{
    google::ShutdownGoogleLogging();
    delete [] buff;
    std::cout << "uninit" << std::endl;
}

void Eventlog::WRITE_LOG(LOG_LEVEL level, const char* strLogStr, ...)
{
    va_list args;
    va_start(args, strLogStr);
    memset(buff, 0, BUFF_SIZE);
    vsnprintf(buff, BUFF_SIZE, strLogStr, args);
    va_end(args);
    switch (level)
    {   
#ifdef DEBUG
        case LOG_LEVEL::DEBUG_LEVEL:
            LOG(INFO) << buff;
            break;
#endif
        case LOG_LEVEL::INFO_LEVEL:
            LOG(INFO) << buff;
            break;    
        case LOG_LEVEL::WARNING_LEVEL:
            LOG(WARNING) << buff;
            break;
        case LOG_LEVEL::ERROR_LEVEL:
            LOG(ERROR) << buff;
            break;
        default:
            break;
    }
}