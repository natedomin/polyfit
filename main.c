#include <stdio.h>
#include <math.h>
#include "polyfit.h"


int main(void)
{
    //const unsigned int order = 3;
    //const unsigned int countOfElements = 5;
    #define ORDER 3
    #define COUNT_OF_ELEMENTS 5

    int result;
    
    // These inputs should result in the following approximate coefficients:
    //    0.5, 2.5, 1, 3
    double    xData[COUNT_OF_ELEMENTS] = {    12.0,
                                              77.8,
                                              44.1,
                                              23.6,
                                             108.2};
    double    yData[COUNT_OF_ELEMENTS] = {  1239.00,
                                          250668.38,
                                           47792.19,
                                            7991.13,
                                          662740.98};
    double    coefficients[ORDER + 1]; // resulting array of coefficients

    // Begin Code...
    // ------------------------------------------
    result = polyfit(xData,
                     yData,
                     COUNT_OF_ELEMENTS,
                     ORDER,
                     coefficients);
    
    if (result == 0)
    {
        printf("Success!\n");
        for (int ii = ORDER; ii >= 0; ii--)
        {
            printf("  coef[%d] =  %f\n", ii, coefficients[ii]);
        }
    }
    else
    {
        printf("Failure!\n");
    }
    return 0;
}
