#include <iostream>
#include <string>
#include "iter.hpp"

void    intSetValue(int& input)
{
    input = 6;
}

void    intMultip(int& input)
{
    std::cout << (input * 2) << std::endl;
}

void    doubleSetValue(double& input)
{
    input = 13.2;
}

void    doubleMultip(double& input)
{
    std::cout << (input * 2) << std::endl;
}

void    dataSetString(std::string& info)
{
    info = "Hello world";
}

void    dataPrintString(std::string& info)
{
    std::cout << info << std::endl;
}

void    dataSetValue(data& d)
{
    d.name = "Tom";
}

void    dataPrintValue(data& d)
{
    std::cout << d.name << std::endl;
}

int     main(void)
{
    std::cout << "---------------int---------------" << std::endl;
    int* testInt = new int[10];

    iter(testInt, 10, &intSetValue); 
    iter(testInt, 10, &intMultip); 

    delete [] testInt;

    std::cout << "---------------double---------------" << std::endl;
    double* testDouble = new double[10];

    iter(testDouble, 10, &doubleSetValue); 
    iter(testDouble, 10, &doubleMultip); 

    delete [] testDouble;

    std::cout << "---------------string---------------" << std::endl;
    std::string* testStr = new std::string[10];

    iter(testStr, 10, &dataSetString); 
    iter(testStr, 10, &dataPrintString); 

    delete [] testStr;

    std::cout << "---------------data---------------" << std::endl;
    data* testData = new data[10];

    iter(testData, 10, &dataSetValue); 
    iter(testData, 10, &dataPrintValue);

    delete [] testData;

    std::cout << "---------------test null---------------" << std::endl;
    data* testNull = NULL;

    iter(testNull, 10, &dataSetValue); 
    iter(testNull, 10, &dataPrintValue);

    return (0);
}