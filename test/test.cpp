#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include "MyTests.h"
#include <cxxtest/ErrorPrinter.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestListener.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/TestTracker.h>

int main(int argc, char* argv[])
{
    int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main<CxxTest::ErrorPrinter>(tmp, argc, argv);
    return status;
}
bool suite_MyTest_init = false;