#ifndef COMMON_H
#define COMMON_H

#include <string>

class Common
{
public:
    static bool isDirExisted(const std::string& DirPath);
    static void createDir(const std::string& DirPath);
};

#endif