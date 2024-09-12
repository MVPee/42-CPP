# include "Span.hpp"

int main(void) {
    std::cout << "*** PART 1 ***" << std::endl;
    Span sp = Span(5);
    try {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "*** PART 2 ***" << std::endl;
    Span sp2 = Span(10000);
    std::vector<int> vector(10000, 10);
    try {
        sp2.addNumber(vector.begin(), vector.end());
        sp2.addNumber(5);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "*** PART 3 ***" << std::endl;
    Span sp3 = Span(5);
    try {
        sp3.shortestSpan();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}
