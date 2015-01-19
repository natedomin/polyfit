#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "polyfit.h"

//----------------------------------------------------
// Execute unit tests
//----------------------------------------------------
int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}

//----------------------------------------------------
// TestPolyfit Test Group declaration
//----------------------------------------------------
TEST_GROUP(TestPolyfit)
{
    void setup()
    {
       // For future use.
    }

    void teardown()
    {
        mock().clear();
    }
};

//----------------------------------------------------
// Testing Third Order Polynomial fitting...
//----------------------------------------------------
TEST(TestPolyfit, ThirdOrderPoly)
{
    const unsigned int order = 3;
    const unsigned int countOfElements = 5;
    const double acceptableError = 0.01;
    int result;

    // These inputs should result in the following approximate coefficients:
    //         0.5           2.5           1.0        3.0
    //    y = (0.5 * x^3) + (2.5 * x^2) + (1.0 * x) + 3.0
    double    xData[countOfElements] = {    12.0,
                                            77.8,
                                            44.1,
                                            23.6,
                                           108.2};
    double    yData[countOfElements] = {  1239.00,
                                        250668.38,
                                         47792.19,
                                          7991.13,
                                        662740.98};
   double coefficients[order + 1]; // resulting array of coefs

   // Perform the polyfit
   result = polyfit(xData,
                    yData,
                    countOfElements,
                    order,
                    coefficients);

   CHECK_EQUAL(result, 0);
   DOUBLES_EQUAL(0.5, coefficients[3], acceptableError);
   DOUBLES_EQUAL(2.5, coefficients[2], acceptableError);
   DOUBLES_EQUAL(1.0, coefficients[1], acceptableError);
   DOUBLES_EQUAL(3.0, coefficients[0], acceptableError);
}


