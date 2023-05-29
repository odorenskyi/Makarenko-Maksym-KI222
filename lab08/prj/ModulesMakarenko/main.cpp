#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <fstream>
#include <locale>
#include <codecvt>
#include "ModulesMakarenko.h"


std::wstring readInputFile(const std::string& fileName) {
    std::wifstream inputFile(fileName);
    if (!inputFile) {
        std::cerr << "�� ������� ������� ���� " << fileName << std::endl;
        return L"";
    }
    inputFile.imbue(std::locale(inputFile.getloc(), new std::codecvt_utf8_utf16<wchar_t>));

    std::wstring inputText;
    std::wstring line;
    while (std::getline(inputFile, line)) {
        inputText += line + L"\n";
    }

    inputFile.close();
    return inputText;
}

void writeOutputFile(const std::string& fileName, const std::wstring& text) {
    std::wofstream outputFile(fileName);
    if (!outputFile) {
        std::cerr << "�� ������� ������� ���� " << fileName << std::endl;
        return;
    }
    outputFile.imbue(std::locale(std::locale(), new std::codecvt_byname<wchar_t, char, std::mbstate_t>("uk_UA.CP1251")));

    outputFile << text;

    outputFile.close();
}

void appendResultsToFile(const std::string& fileName, double s, const std::string& binary) {
    std::ofstream outputFile(fileName, std::ios::app);
    if (!outputFile) {
        std::cerr << "�� ������� ������� ���� " << fileName << std::endl;
        return;
    }

    outputFile << "���������� ��������� ������� s_calculation:" << std::endl;
    outputFile << "s = " << s << std::endl;
    outputFile << "b � ��������� ���: " << binary << std::endl;

    time_t currentTime = std::time(nullptr);
    tm* localTime = std::localtime(&currentTime);
    int day = localTime->tm_mday;
    int month = localTime->tm_mon + 1;
    int year = localTime->tm_year + 1900;

    outputFile << "���� �������� ����������: " << day << "/" << month << "/" << year << std::endl;

    outputFile.close();
}

double toRadians(double angleInDegrees) {
    double angleInRadians = angleInDegrees * M_PI / 180.0;
    return angleInRadians;
}

double s_calculation(double x, double y, double z) {
    x = toRadians(x);
    y = toRadians(y);
    z = toRadians(z);
    double s = 0;
    s = z + M_PI * (((std::pow((2 * z + 1), 2) - std::sqrt(std::abs((y - (1 / 2) * z))))) / (std::cos(z + y * z) + std::pow(x, 2)));
    return s;
}

std::string getBin(unsigned int decimalNumber) {
    std::string binary = "";
    while (decimalNumber > 0) {
        int rem = decimalNumber % 2;
        binary = std::to_string(rem) + binary;
        decimalNumber /= 2;
    }
    return binary;
}

bool isVowel(wchar_t c) {
    c = std::tolower(c, std::locale("uk_UA.UTF-8"));
    return (c == L'�' || c == L'�' || c == L'�' || c == L'�' || c == L'�' || c == L'�' || c == L'�' || c == L'�' || c == L'�' || c == L'�');
}

std::wstring transliterateCharacter(wchar_t c) {
    wchar_t lowercaseChar = std::tolower(c, std::locale("uk_UA.UTF-8"));
    std::wstring result;
    switch (lowercaseChar) {
        case L'�':
            result += (c == L'�') ? L"A" : L"a";
            break;
        case L'�':
            result += (c == L'�') ? L"B" : L"b";
            break;
        case L'�':
            result += (c == L'�') ? L"V" : L"v";
            break;
        case L'�':
            result += (c == L'�') ? L"H" : L"h";
            break;
        case L'�':
            result += (c == L'�') ? L"G" : L"g";
            break;
        case L'�':
            result += (c == L'�') ? L"D" : L"d";
            break;
        case L'�':
            result += (c == L'�') ? L"E" : L"e";
            break;
        case L'�':
            result += (c == L'�') ? L"IE" : L"ie";
            break;
        case L'�':
            result += (c == L'�') ? L"ZH" : L"zh";
            break;
        case L'�':
            result += (c == L'�') ? L"Z" : L"z";
            break;
        case L'�':
            result += (c == L'�') ? L"Y" : L"y";
            break;
        case L'�':
            result += (c == L'�') ? L"I" : L"i";
            break;
        case L'�':
            result += (c == L'�') ? L"YI" : L"yi";
            break;
        case L'�':
            result += (c == L'�') ? L"I" : L"i";
            break;
        case L'�':
            result += (c == L'�') ? L"K" : L"k";
            break;
        case L'�':
            result += (c == L'�') ? L"L" : L"l";
            break;
        case L'�':
            result += (c == L'�') ? L"M" : L"m";
            break;
        case L'�':
            result += (c == L'�') ? L"N" : L"n";
            break;
        case L'�':
            result += (c == L'�') ? L"O" : L"o";
            break;
        case L'�':
            result += (c == L'�') ? L"P" : L"p";
            break;
        case L'�':
            result += (c == L'�') ? L"R" : L"r";
            break;
        case L'�':
            result += (c == L'�') ? L"S" : L"s";
            break;
        case L'�':
            result += (c == L'�') ? L"T" : L"t";
            break;
        case L'�':
            result += (c == L'�') ? L"U" : L"u";
            break;
        case L'�':
            result += (c == L'�') ? L"F" : L"f";
            break;
        case L'�':
            result += (c == L'�') ? L"KH" : L"kh";
            break;
        case L'�':
            result += (c == L'�') ? L"TS" : L"ts";
            break;
        case L'�':
            result += (c == L'�') ? L"CH" : L"ch";
            break;
        case L'�':
            result += (c == L'�') ? L"SH" : L"sh";
            break;
        case L'�':
            result += (c == L'�') ? L"SHCH" : L"shch";
            break;
        case L'�':
            result += (c == L'�') ? L"'" : L"'";
            break;
        case L'�':
            result += (c == L'�') ? L"IU" : L"iu";
            break;
        case L'�':
            result += (c == L'�') ? L"IA" : L"ia";
            break;
        default:
            result += c;
            break;
    }
    return result;
}

std::wstring transliterate(const std::wstring& input) {
    std::wstring result;
    for (const auto& c : input) {
        result += transliterateCharacter(c);
    }
    return result;
}

std::wstring readInputFile(const std::string& fileName) {
    std::wifstream inputFile(fileName);
    if (!inputFile) {
        std::cerr << "�� ������� ������� ���� " << fileName << std::endl;
        return L"";
    }
    inputFile.imbue(std::locale(inputFile.getloc(), new std::codecvt_utf8_utf16<wchar_t>));

    std::wstring inputText;
    std::wstring line;
    while (std::getline(inputFile, line)) {
        inputText += line + L"\n";
    }

    inputFile.close();
    return inputText;
}

void writeOutputFile(const std::string& fileName, const std::wstring& text) {
    std::wofstream outputFile(fileName);
    if (!outputFile) {
        std::cerr << "�� ������� ������� ���� " << fileName << std::endl;
        return;
    }
    outputFile.imbue(std::locale(std::locale(), new std::codecvt_byname<wchar_t, char, std::mbstate_t>("uk_UA.CP1251")));

    outputFile << text;

    outputFile.close();
}

void processFile(const std::string& inputFileName, const std::string& outputFileName, const std::string& input10_3FileName) {
    std::wstring inputText = readInputFile(inputFileName);
    writeOutputFile(outputFileName, transliterate(inputText));

    std::wstring input10_3Text = readInputFile(input10_3FileName);
    std::wstringstream inputStream(input10_3Text);

    std::wofstream outputFile(outputFileName, std::ios::app);
    if (!outputFile) {
        std::cerr << "�� ������� ������� ���� " << outputFileName << std::endl;
        return;
    }
    outputFile.imbue(std::locale(outputFile.getloc(), new std::codecvt_utf8_utf16<wchar_t>));

    double x, y, z, b;
    while (inputStream >> x >> y >> z >> b) {
        double s = s_calculation(x, y, z);
        std::string binary = getBin(static_cast<unsigned int>(b));
        outputFile << L"s = " << s << L", b (binary) = " << std::wstring(binary.begin(), binary.end()) << std::endl;
    }

    outputFile.close();
}




