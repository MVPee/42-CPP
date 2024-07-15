# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main(void) {
    std::cout << std::endl;
    std::cout << "PART 1." << std::endl;
    try {
        Bureaucrat perfecto("Perfecto", 1);
        ShrubberyCreationForm formatator("Formatator");
        perfecto.signForm(formatator);
        formatator.execute(perfecto);
    }
    catch (std::exception & e) {
        std::cerr << ORANGE << e.what() << NONE <<std::endl;
    }

    std::cout << std::endl;
    std::cout << "PART 2." << std::endl;
    try {
        Bureaucrat perfecto("Perfecto", 1);
        RobotomyRequestForm formatator("Formatator");
        perfecto.signForm(formatator);
        formatator.execute(perfecto);
    }
    catch (std::exception & e) {
        std::cerr << ORANGE << e.what() << NONE <<std::endl;
    }

    std::cout << std::endl;
    std::cout << "PART 3." << std::endl;
    try {
        Bureaucrat perfecto("Perfecto", 1);
        PresidentialPardonForm formatator("Formatator");
        perfecto.signForm(formatator);
        formatator.execute(perfecto);
    }
    catch (std::exception & e) {
        std::cerr << ORANGE << e.what() << NONE <<std::endl;
    }
    return (0);
}