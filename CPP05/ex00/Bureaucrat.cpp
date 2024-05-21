#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : name("NONE"), grade(150) {
	std::cout << GREEN << "[ Bureaucrat ] Constructer called." << NONE << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat() {
	std::cout << RED << "[ Bureaucrat ] Destructor called." << NONE << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat& Bureaucrat::operator=( Bureaucrat const& rhs ) {
	if (this != &rhs) {
        this->name = rhs.name;
        this->grade = rhs.grade;
    }
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/



/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string& Bureaucrat::getName(void) const { return (name); }

/* ************************************************************************** */