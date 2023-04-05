#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;


double s_calculation(int x, int y, int z){
    double s = 0;
    s = z + M_PI *(((pow((2 * z + 1), 2) - sqrt(abs((y - (1/2) * z))))/(cos(z + y * z) + pow(x, 2))));
    return s;
}

double getAmountDue(int consumedEnergy){
    if (consumedEnergy <= 150){
        return (consumedEnergy * 0.3084);
    }if (consumedEnergy > 150 && consumedEnergy <= 800){
        return (consumedEnergy * 0.4194);
    }else{
        return (consumedEnergy * 1.3404);
    }
}
int getBeaufortOfMin(float winds[]) {
    float* minWindPtr = min_element(winds, winds + 6);
    float minWindVal = *minWindPtr;

    if (minWindVal >= 0 && minWindVal <= 0.5) {
        return 0;
    } else if (minWindVal > 0.5 && minWindVal <= 1.5) {
        return 1;
    } else if (minWindVal > 1.5 && minWindVal <= 3.3) {
        return 2;
    } else if (minWindVal > 3.3 && minWindVal <= 5.4) {
        return 3;
    } else if (minWindVal > 5.4 && minWindVal <= 7.9) {
        return 4;
    } else if (minWindVal > 7.9 && minWindVal <= 10.7) {
        return 5;
    } else if (minWindVal > 10.7 && minWindVal <= 13.8) {
        return 6;
    } else if (minWindVal > 13.8 && minWindVal <= 17.1) {
        return 7;
    } else if (minWindVal > 17.1 && minWindVal <= 20.7) {
        return 8;
    } else if (minWindVal > 20.7 && minWindVal <= 24.4) {
        return 9;
    } else if (minWindVal > 24.4 && minWindVal <= 28.4) {
        return 10;
    } else if (minWindVal > 28.4 && minWindVal <= 32.6) {
        return 11;
    } else if (minWindVal > 32.6) {
        return 12;
    }
}
unsigned short int getBinary(unsigned int decimalNumber){
    string binary = "";
    while (decimalNumber > 0) {
        int rem = decimalNumber % 2;
        binary = to_string(rem) + binary;
        decimalNumber /= 2;
    }


    if (binary[8] == '1'){
        int counter = 0;

        for (char c : binary) {
            if (c == '0') {
                counter++;
        }
    }

        cout << "Кількість нулів в бінарному числі: " << counter << endl;
        return counter;
    }
    else{
        int counter = 0;

        for (char c : binary) {
            if (c == '1') {
                counter++;
        }
    }
        cout << "Кількість одиниць в бінарному числі: " << counter << endl;
        return counter;
    }

}




