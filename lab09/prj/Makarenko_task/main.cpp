#include <iostream>
#include "ModulesMakarenko.h"
#include <iomanip>
#include <cmath>

int main()
{
    system("chcp 1251");
    system("cls");
    bool killSwitch = false;
    char action;
    int x, y, z, consumedEnergy;
    int windTime = 0;
    float winds[6];
    unsigned int decimalNumber;

    while (killSwitch == false) {
        std::cout << "������ ������ ��� �������� 䳿: ";
        std::cin >> action;
        switch (action) {
        case 'd':

            std::cout << "������ x, y, z: ";
            std::cin >> x >> y >> z;
            std::cout << s_calculation(x, y, z) << std::endl;
            break;
        case 'g':

            std::cout << "������ ������� ������� �� ����� �����������㳿 (���*���): " << std::endl;
            std::cin >> consumedEnergy;

            std::cout << "���� �� ������ � ������� �������� �� ������: " << std::fixed << std::setprecision(2) << getAmountDue(consumedEnergy) << " ���" << std::endl;
            break;

        case 'h':

            for (int i = 0; i < 6; i++) {
                std::cout << "������ ��������� ���� ��� " << windTime << ":00: ";
                std::cin >> winds[i];
                windTime += 4;
            }
            std::cout << "��� ������� ���������� ���������: " << getBeaufortOfMin(winds) << std::endl;
            break;

        case 'j':

            std::cout << "������ ���������� �����: ";
            std::cin >> decimalNumber;

            getBinary(decimalNumber);
            break;

        case 'k':
        case 'K':
        case '�':
            killSwitch = true;
            break;
        default:
            std::cout << "\a";
            break;
        }
    }
    return 0;
}

