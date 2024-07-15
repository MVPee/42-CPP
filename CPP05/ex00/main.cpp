#include "Bureaucrat.hpp"

int main(void) {
    std::cout << std::endl;
    std::cout << "PART 1." << std::endl;
    try {
        Bureaucrat test("Low", 151);
    }
    catch (std::exception & e) {
        std::cerr << ORANGE << e.what() << NONE <<std::endl;
    }
    try {
        Bureaucrat test1("Hight", 0);
    }
    catch (std::exception & e) {
        std::cerr << ORANGE << e.what() << NONE <<std::endl;
    }
    
    std::cout << std::endl;
    std::cout << "PART 2." << std::endl;
    try {
        Bureaucrat test2("increment", 0);
        test2.increment();
    }
    catch (std::exception & e) {
        std::cerr << ORANGE << e.what() << NONE <<std::endl;
    }
    try {
        Bureaucrat test3("decrement", 150);
        test3.decrement();
    }
    catch (std::exception & e) {
        std::cerr << ORANGE << e.what() << NONE <<std::endl;
    }

    std::cout << std::endl;
    std::cout << "PART 3." << std::endl;
    try {
        Bureaucrat MVP("MVP", 2);
        MVP.increment();
        std::cout << ORANGE << MVP << NONE << std::endl;
    }
    catch (std::exception & e) {
        std::cerr << ORANGE << e.what() << NONE <<std::endl;
    }

    return (0);
}