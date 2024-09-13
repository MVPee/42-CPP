# include "BitcoinExchange.hpp"

int main(int ac, char **av) {

    if (ac != 2) {
        std::cerr << "Number(s) of agurment(s)\nWaiting input.txt" << std::endl;
        return 1;
    }
    std::ifstream data("./data.csv");
    if (!data.is_open() || !data.good()) {
        std::cerr << "No valid \"data.csv\" file" << std::endl;
        return 1;
    }
    std::ifstream file;
    file.open(av[1]);
    if (!file.is_open() || !file.good()) {
        data.close();
        std::cerr << "No valid \"input.txt\" file" << std::endl;
        return 1;
    }

    BitcoinExchange btc(data);

    std::string line;
    std::getline(file, line);
    while(std::getline(file, line))
        btc.processLine(line);

    data.close();
    file.close();
}