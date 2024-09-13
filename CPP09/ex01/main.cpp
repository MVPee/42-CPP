# include "RPN.hpp"

static bool check_input(const std::string &input) {
    for (size_t i = 0; i < input.size(); i++) {
        if (input.at(i) != '*' && input.at(i) != '-' && input.at(i) != '+' &&
            input.at(i) != '/' && input.at(i) != ' ' && !(std::isdigit(input.at(i)))) {
                std::cerr << "Error: " << input.at(i) << std::endl;
                return true;
            }
    }
    return false;
}

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Number(s) of argument(s)" << std::endl;
        return (1);
    }
    std::string input(av[1]);
    if (check_input(input))
        return (1);
    RPN rpn;
    rpn.process(input);
}