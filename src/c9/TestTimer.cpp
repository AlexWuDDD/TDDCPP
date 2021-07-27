#include "CppUTest/Utest.h"
#include "TestTimer.h"
#include <iostream>

TestTimer::TestTimer()
    : TestTimer(UtestShell::getCurrent()->getName().asCharString())
{}

TestTimer::TestTimer(const std::string& text)
    : Start{std::chrono::system_clock::now()}
    , Text{text}
{}

TestTimer::~TestTimer()
{
    Stop = std::chrono::system_clock::now();
    Elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(Stop - Start);
    std::cout << std::endl 
        << Text << " elapsed time = " << Elapsed.count() * 0.001<< " ms" << std::endl;
}
