#ifndef EVENTLOG_H
#define EVENTLOG_H

#include <string>

class Eventlog
{
public:
    static Eventlog & GetInstance(const std::string& logDir);
private:
    Eventlog(const std::string& logDir);
    ~Eventlog();

    Eventlog(const Eventlog&) = delete;
    Eventlog& operator=(const Eventlog&) = delete;
};


#endif