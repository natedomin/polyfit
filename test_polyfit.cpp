#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include <stdio.h>
#include "polyfit.h"


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

    CHECK_EQUAL(0, result);
    DOUBLES_EQUAL(0.5, coefficients[3], acceptableError);
    DOUBLES_EQUAL(2.5, coefficients[2], acceptableError);
    DOUBLES_EQUAL(1.0, coefficients[1], acceptableError);
    DOUBLES_EQUAL(3.0, coefficients[0], acceptableError);
}

//----------------------------------------------------
// Verify incorrect result - insufficient count of xData
// and yData for the specified polyfit order.
//----------------------------------------------------
TEST(TestPolyfit, InsufficientInputData)
{
    const unsigned int order = 3;
    const unsigned int countOfElements = 2;
    int result;

    // These inputs should result in the following approximate coefficients:
    //         0.1           -3.2           -0.1        40.0
    //    y = (0.1 * x^3) + (-3.2 * x^2) + (-0.1 * x) + 40.0
    double    xData[countOfElements] = {    15.0,
                                            77.0};
    double    yData[countOfElements] = {  -344.0,
                                         26712.8};
    double coefficients[order + 1]; // resulting array of coefs

   // Perform the polyfit
   result = polyfit(xData,
                    yData,
                    countOfElements,
                    order,
                    coefficients);

   CHECK_EQUAL(-1, result);
}

