# include "Bureaucrat.hpp"
# include "Form.hpp"

int main(void) {
    std::cout << std::endl;
    std::cout << "PART 1." << std::endl;
    try {
        Bureaucrat perfecto("Perfecto", 150);
        Form form("Form", 149, 150);
        form.beSigned(perfecto);
    }
    catch (std::exception & e) {
        std::cerr << ORANGE << e.what() << NONE <<std::endl;
    }

    std::cout << std::endl;
    std::cout << "PART 2." << std::endl;
    try {
        Bureaucrat perfectator("Perfectator", 150);
        Form formatator("Formatator", 150, 150);
        perfectator.signForm(formatator);

        Bureaucrat perfectator2("Perfectator", 149);
        Form formatator2("Formatator", 140, 150);
        perfectator2.signForm(formatator2);
    }
    catch (std::exception & e) {
        std::cerr << ORANGE << e.what() << NONE <<std::endl;
    }
    return (0);
}