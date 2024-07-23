# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"

int main(void) {
    Intern someRandomIntern;
    AForm* rrf;
    try {
        rrf = someRandomIntern.makeForm(ROBOTOMY_REQUEST_FORM, "BRRRrrzR");
        std::cout << "Name: " << rrf->getName() << std::endl;
        Bureaucrat bureaucrat("Georges", 1);
        bureaucrat.signForm(*rrf);
        bureaucrat.executeForm(*rrf);
        delete rrf;
    }
    catch (std::exception &e) {
        std::cerr << ORANGE << e.what() << NONE << std::endl;
    }

    std::cout << std::endl;

    try {
        rrf = someRandomIntern.makeForm(PRESIDENTIAL_PARDON_FORM, "Trumpet");
        std::cout << "Name: " << rrf->getName() << std::endl;
        delete rrf;
    }
    catch (std::exception &e) {
        std::cerr << ORANGE << e.what() << NONE << std::endl;
    }

    std::cout << std::endl;

    try {
        rrf = someRandomIntern.makeForm(SHRUBBERY_CREATION_FORM, "TREE");
        std::cout << "Name: " << rrf->getName() << std::endl;
        delete rrf;
    }
    catch (std::exception &e) {
        std::cerr << ORANGE << e.what() << NONE << std::endl;
    }

    std::cout << std::endl;

    try {
        rrf = someRandomIntern.makeForm("Something", "TREE");
        std::cout << "Name: " << rrf->getName() << std::endl;
        delete rrf;
    }
    catch (std::exception &e) {
        std::cerr << ORANGE << e.what() << NONE << std::endl;
    }
    return (0);
}