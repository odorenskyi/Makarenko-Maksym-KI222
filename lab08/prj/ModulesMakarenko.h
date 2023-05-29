#pragma once

#include <string>

std::wstring readInputFile(const std::string& fileName);
void writeOutputFile(const std::string& fileName, const std::wstring& text);
void processFile(const std::string& inputFileName, const std::string& outputFileName, const std::string& input10_3FileName);

double toRadians(double angleInDegrees);
double s_calculation(double x, double y, double z);
std::string getBin(unsigned int decimalNumber);
bool isVowel(wchar_t c);
std::wstring transliterateCharacter(wchar_t c);
std::wstring transliterate(const std::wstring& input);
void appendResultsToFile(const std::string& fileName, double s, const std::string& binary);
