# include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name), _grade(grade) {
	std::cout << GREEN << "[ Bureaucrat " + this->_name + " ] Constructer called." << NONE << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name), _grade(other._grade) {
	std::cout << GREEN << "[ Bureaucrat " + this->_name + " ] Copied Constructer called." << NONE << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat() {
	std::cout << RED << "[ Bureaucrat " + this->_name + " ] Destructor called." << NONE << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat& Bureaucrat::operator=( Bureaucrat const& rhs ) {
	if (this != &rhs)
        this->_grade = rhs._grade;
	return *this;
}

std::ostream& operator<<(std::ostream & o, Bureaucrat const & i) {
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
	return (o);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Bureaucrat::increment(void) {
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrement(void) {
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << ORANGE << this->_name << " couldn’t sign " << form.getName() << " because:\n" << \
		this->_name << "'s grade (" << this->_grade << ") < " << form.getName() << \
		" minimum grade to sign (" << form.getSignGrade() << ")." <<  NONE << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const {
    try {
        std::cout << this->_name << " executed " << form.getName() << std::endl;
        form.execute(*this);
    }
	catch (const std::exception &e) {
        std::cerr << ORANGE << this->_name << " couldn’t execute " << form.getName() << " because:\n" << \
		this->_name << "'s grade (" << this->_grade << ") < " << form.getName() << \
		" minimum grade to execute (" << form.getExecuteGrade() << ")." <<  NONE << std::endl;
    }
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Bureaucrat::getName(void) const { return (this->_name); }
int Bureaucrat::getGrade(void) const { return (this->_grade); }

/*
** --------------------------------- EXCEPTIONS -------------------------------
*/

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("[Bureaucrat] Grade is too hight ( < 1 )!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("[Bureaucrat] Grade is too low ( > 150 )!");
}

/* ************************************************************************** */