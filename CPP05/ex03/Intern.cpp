#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern() {
}

Intern::Intern(const Intern &src) {
	(void)src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern() {
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &Intern::operator=(Intern const &rhs) {
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

AForm* Intern::makeForm(std::string name, std::string target) {
	std::string formNames[] = {
		ROBOTOMY_REQUEST_FORM,
		PRESIDENTIAL_PARDON_FORM,
		SHRUBBERY_CREATION_FORM
	};
	
	for (int i = 0; i < 3; i++) {
		if (name == formNames[i]) {
			std::cout << "Intern creates " << name << std::endl;
			switch (i) {
				case ROBOTOMY_FORM:
					return (new RobotomyRequestForm(target));
				case PRESIDENTIAL_FORM:
					return (new PresidentialPardonForm(target));
				case SHRUBBERY_FORM:
					return (new ShrubberyCreationForm(target));
			}
		}
	}

	std::cout << "Intern cannot create " << name << " form" << std::endl;
	throw FormDoesNotExist();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/*
** --------------------------------- EXCEPTIONS -------------------------------
*/

const char *Intern::FormDoesNotExist::what() const throw() {
	return ("This form doesn't exist...");
}

/* ************************************************************************** */