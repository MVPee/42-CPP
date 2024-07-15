#include "Bureaucrat.hpp"

int main(void) {
    try {
        Bureaucrat test("Low", 151);
    } catch (std::exception & e) {
        std::cerr << ORANGE << e.what() << NONE <<std::endl;
    }

    try {
        Bureaucrat test1("Hight", 0);
    } catch (std::exception & e) {
        std::cerr << ORANGE << e.what() << NONE <<std::endl;
    }
    
    Bureaucrat test2("increment", 1);
    try {
        test2.increment();
    } catch (std::exception & e) {
        std::cerr << ORANGE << e.what() << NONE <<std::endl;
    }

    Bureaucrat test3("decrement", 150);
    try {
        test3.decrement();
    } catch (std::exception & e) {
        std::cerr << ORANGE << e.what() << NONE <<std::endl;
    }

    Bureaucrat MVP("MVP", 2);
    try {
        MVP.increment();
    } catch (std::exception & e) {
        std::cerr << ORANGE << e.what() << NONE <<std::endl;
    }
    std::cout << ORANGE << MVP << NONE << std::endl;
    return (0);
}