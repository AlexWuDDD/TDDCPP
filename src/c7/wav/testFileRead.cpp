#include <fstream>
#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{
    std::string name = "../src/c7/wav/test.txt";
    std::ifstream file{name, std::ios::in | std::ios::binary};
    if (!file.is_open()) {
        std::cerr << "File not found" << std::endl;
        return -1;
    }
    char buf[9] = {0};
    file.read(buf, 9);
    std::cout << buf << std::endl;

    memset(buf, 0, 9);
    file.read(buf, 9);
    std::cout << buf << std::endl;
    
    memset(buf, 0, 9);
    file.read(buf, 9);
    std::cout << buf << std::endl;

    file.close();

    return 0;
}
