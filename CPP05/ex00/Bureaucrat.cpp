#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
	std::cout << GREEN << "[ Bureaucrat " + this->name + " ] Constructer called." << NONE << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {
	std::cout << GREEN << "[ Bureaucrat " + this->name + " ] Copied Constructer called." << NONE << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat() {
	std::cout << RED << "[ Bureaucrat " + this->name + " ] Destructor called." << NONE << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat& Bureaucrat::operator=( Bureaucrat const& rhs ) {
	if (this != &rhs)
        this->grade = rhs.grade;
	return *this;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & i) {
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
	return (o);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Bureaucrat::increment(void) {
	if (this->grade - 1 < 1)
		throw GradeTooHighException();
	else
		this->grade = this->grade - 1;
}

void Bureaucrat::decrement(void) {
	if (this->grade + 1 > 150)
		throw GradeTooHighException();
	else
		this->grade = this->grade + 1;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Bureaucrat::getName(void) const { return (name); }
int Bureaucrat::getGrade(void) const { return (grade); }

/*
** --------------------------------- Exceptions --------------------------------
*/

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too hight ( < 1 )!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low ( > 150 )!");
}

/* ************************************************************************** */