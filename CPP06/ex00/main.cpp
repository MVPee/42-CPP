# include "ScalarConverter.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Number(s) of argument(s)..." << std::endl;
        return (1);
    }
    ScalarConverter::convert(av[1]);
    return (0);
}