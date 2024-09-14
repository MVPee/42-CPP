# include "PmergeMe.hpp"

int main(int ac, char **av) {
    srand(time(NULL));
    if (ac < 3) {
        std::cerr << "Error: Need two numbers at least" << std::endl;
        return 1;
    }
    PmergeMe pleaseMergeMe(ac, av);
}