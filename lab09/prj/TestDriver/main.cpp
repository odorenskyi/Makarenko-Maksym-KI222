#include <iostream>
#include <iomanip>
#include <string>
#include "ModulesMakarenko.h"
#define ARRAY_SIZE 6

int main()
{
    system("chcp 1251");
    system("cls");

    int inputConsEnergy[ARRAY_SIZE] = {100, 150, 300, 500, 700, 1000};
    float inputWind[ARRAY_SIZE][6] = {{12, 43, 42, 5.23, 2, 42.123},
                                             {442.42, 42, 12, 43.232, 53, 53},
                                             {32, 42, 12, 14, 16, 17},
                                             {45, 524, 53, 12, 15, 1},
                                             {442, 42, 12.42, 0.3, 53.4, 53},
                                             {32.1, 54, 12.2, 1, 16.43, 0.2}};
    unsigned int inputDecimal[ARRAY_SIZE] = {123, 421, 14242, 432, 53234, 0};

    float outputAmountDue[ARRAY_SIZE] = {30.84, 46.26, 125.82, 209.70, 293.58, 1340.40};
    float outputWind[ARRAY_SIZE] = {2, 6, 6, 1, 0, 0};
    unsigned short int outputBinary[ARRAY_SIZE] = {6, 4, 6, 4, 5, 0};

    // Test getAmountDue
    for (int i = 0; i < ARRAY_SIZE; i++) {
        float result = getAmountDue(inputConsEnergy[i]);
        if (result == outputAmountDue[i]) {
            std::cout << "getAmountDue test " << i+1 << " passed.\n";
        } else {
            std::cout << "getAmountDue test " << i+1 << " failed. Expected: " << outputAmountDue[i]
                      << " Actual: " << result << std::endl;
        }
    }

    // Test getBeaufortOfMin
    for (int i = 0; i < ARRAY_SIZE; i++) {
        float result = getBeaufortOfMin(inputWind[i]);
        if (result == outputWind[i]) {
            std::cout << "getBeaufortOfMin test " << i+1 << " passed.\n";
        } else {
            std::cout << "getBeaufortOfMin test " << i+1 << " failed. Expected: " << outputWind[i]
                      << " Actual: " << result << std::endl;
        }
    }

    // Test getBinary
    for (int i = 0; i < ARRAY_SIZE; i++) {
        unsigned short int result = getBinary(inputDecimal[i]);
        if (result == outputBinary[i]) {
            std::cout << "getBinary test " << i+1 << " passed.\n";
        } else {
            std::cout << "getBinary test " << i+1 << " failed. Expected: " << outputBinary[i]
                      << " Actual: " << result << std::endl;
        }
    }

    return 0;
}
