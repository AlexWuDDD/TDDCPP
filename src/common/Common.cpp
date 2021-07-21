#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "Common.h"

bool Common::isDirExisted(const std::string& DirPath)
{
    return access(DirPath.c_str(), F_OK) == 0;
}

void Common::createDir(const std::string& DirPath)
{
    if(!isDirExisted(DirPath)){
        mkdir(DirPath.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    }
}