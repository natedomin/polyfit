#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

//----------------------------------------------------
// Execute all unit tests
//----------------------------------------------------
int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}


