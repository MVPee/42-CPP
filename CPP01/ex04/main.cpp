#include <iostream>
#include <fstream>

void replace_in_outputfile(std::ifstream& input, std::ofstream& output, const std::string& str1, const std::string& str2) {
    std::string line;
    while (std::getline(input, line)) {
        size_t pos = 0;
        while ((pos = line.find(str1, pos)) != std::string::npos) {
            line = line.substr(0, pos) + str2 + line.substr(pos + str1.length());
            pos += str2.length();
        }
        output << line << '\n';
    }
}

int main(int ac, char **av) {

    if (ac != 4)
        return (1);

    std::ifstream inputFile(av[1]);
    if (!inputFile.is_open())
        return (std::cout << "Input file is not good!" << std::endl, 1);

    std::ofstream outputFile;
    std::string outputFileName = std::string(av[1]).append(".replace");
    outputFile.open(outputFileName.c_str(), std::ofstream::out | std::ofstream::trunc);
    if (!outputFile.is_open())
        return (inputFile.close(), std::cout << "Output file is not good!" << std::endl, 1);

    replace_in_outputfile(inputFile, outputFile, av[2], av[3]);   

    inputFile.close();
    outputFile.close();
    return (0);
}