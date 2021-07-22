#ifndef EVENTLOG_H
#define EVENTLOG_H

#include <string>

#define BUFF_SIZE 265
#define LOG_FILE_PREFIEX "./MyLogs/eventlog_"
#define LOG_DIR "./MyLogs"
#define EACH_LOG_SIZE 10 //MB
#define DEBUG 0
#define OUTPUT_TO_CONSOLE 1

enum LOG_LEVEL{
    DEBUG_LEVEL = 0,
    INFO_LEVEL,
    WARNING_LEVEL,
    ERROR_LEVEL,
};

class Eventlog
{
public:
    static Eventlog & GetInstance();
    void WRITE_LOG(LOG_LEVEL level, const char* strLogStr, ...);
private:
    Eventlog();
    ~Eventlog();

    Eventlog(const Eventlog&) = delete;
    Eventlog& operator=(const Eventlog&) = delete;

    char* buff;
};

#define LOG_DEBUG(strLogStr, ...) Eventlog::GetInstance().WRITE_LOG(LOG_LEVEL::DEBUG_LEVEL, strLogStr, ##__VA_ARGS__)
#define LOG_INFO(strLogStr, ...) Eventlog::GetInstance().WRITE_LOG(LOG_LEVEL::INFO_LEVEL, strLogStr, ##__VA_ARGS__)
#define LOG_WARNING(strLogStr, ...) Eventlog::GetInstance().WRITE_LOG(LOG_LEVEL::WARNING_LEVEL, strLogStr, ##__VA_ARGS__)
#define LOG_ERROR(strLogStr, ...) Eventlog::GetInstance().WRITE_LOG(LOG_LEVEL::ERROR_LEVEL, strLogStr, ##__VA_ARGS__)

#endif