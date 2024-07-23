# include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm()
	: _name("Default"), _signed(false), _signGrade(1), _executeGrade(1) {
	std::cout << GREEN << "Default constructer called." << NONE << std::endl;
}

AForm::AForm(const std::string name, int signGrade, int executeGrade)
	: _name(name), _signed(0), _signGrade(signGrade), _executeGrade(executeGrade) {
	std::cout << GREEN << "[ AForm " + this->_name + " ] Constructer called." << NONE << std::endl;
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm( const AForm & src ) 
	: _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _executeGrade(src._executeGrade) {
	std::cout << GREEN << "[ AForm " + this->_name + " ] Copied constructer called." << NONE << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm() {
	std::cout << RED << "[ AForm " + this->_name + " ] Destructor called." << NONE << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &AForm::operator=(AForm const &rhs) {
    if (this != &rhs) {
        this->_signed = rhs._signed;
    }
    return *this;
}

std::ostream& operator<<( std::ostream & o, AForm const & i ) {
	o << "Name: " << i.getName() << "\n";
	o << "Signed: " << (i.getSigned() ? "signed" : "not signed") << "\n";
	o << "Grade to sign: " << i.getSignGrade() << "\n";
	o << "Grade to execute: " << i.getExecuteGrade();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void AForm::beSigned(Bureaucrat &bureaucrat) {

	if (bureaucrat.getGrade() <= this->_signGrade)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

void AForm::checkExecution(const Bureaucrat &executor) const {
    if (!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > _executeGrade)
        throw GradeTooLowException();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string AForm::getName() const {
	return (this->_name);
}

bool AForm::getSigned() const {
	return (this->_signed);
}

int AForm::getSignGrade() const {
	return (this->_signGrade);
}

int AForm::getExecuteGrade()const {
	return (this->_executeGrade);
}



/*
** --------------------------------- EXCEPTIONS -------------------------------
*/

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

/* ************************************************************************** */