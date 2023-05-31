#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ModulesMakarenko.h"

int main() {

    std::vector<std::string> inputFiles = { "inputFiles/input1.txt", "inputFiles/input2.txt", "inputFiles/input3.txt", "inputFiles/input4.txt", "inputFiles/input5.txt" };
    std::vector<std::string> outputFiles = { "outputFiles/output1.txt", "outputFiles/output2.txt", "outputFiles/output3.txt", "outputFiles/output4.txt", "outputFiles/output5.txt" };
    std::string input10_3File = "input_10_3.txt";

    for (size_t i = 0; i < inputFiles.size(); i++) {
        processFile(inputFiles[i], outputFiles[i], input10_3File);
    }

    return 0;
}

