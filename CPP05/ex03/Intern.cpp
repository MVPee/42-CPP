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

static AForm *newShrubbery(const std::string target) {
	return (new ShrubberyCreationForm(target));
}

static AForm *newRobotomy(const std::string target) {
	return (new RobotomyRequestForm(target));
}

static AForm *newPresidential(const std::string target) {
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string name, std::string target) {
	std::string formNames[] = {
		ROBOTOMY_REQUEST_FORM,
		PRESIDENTIAL_PARDON_FORM,
		SHRUBBERY_CREATION_FORM
	};
	
	AForm* (*formConstructors[3])(const std::string) = {&newShrubbery, &newPresidential, &newRobotomy};

	for (int i = 0; i < 3; i++) {
		if (name == formNames[i]) {
			std::cout << "Intern creates " << name << std::endl;
			return (formConstructors[i](target));
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