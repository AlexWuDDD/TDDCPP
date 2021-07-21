#include "Eventlog.h"
#include "Common.h"

int main(int argc, char const *argv[])
{
    std::string logDir = "MyLogs";
    Common::createDir(logDir);

    return 0;
}
