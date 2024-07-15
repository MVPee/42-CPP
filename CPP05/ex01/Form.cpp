# include "Form.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form()
	: _name("Default"), _signed(false), _signGrade(1), _executeGrade(1) {
	std::cout << GREEN << "Default constructer called." << NONE << std::endl;
}

Form::Form(const std::string name, int signGrade, int executeGrade)
	: _name(name), _signed(0), _signGrade(signGrade), _executeGrade(executeGrade) {
	std::cout << GREEN << "[ Form " + this->_name + " ] Constructer called." << NONE << std::endl;
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

Form::Form( const Form & src ) 
	: _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _executeGrade(src._executeGrade) {
	std::cout << GREEN << "[ Form " + this->_name + " ] Copied constructer called." << NONE << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form() {
	std::cout << RED << "[ Form " + this->_name + " ] Destructor called." << NONE << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &Form::operator=(Form const &rhs)
{
    if (this != &rhs) {
        this->_signed = rhs._signed;
    }
    return *this;
}

std::ostream& operator<<( std::ostream & o, Form const & i ) {
	o << "Name: " << i.getName() << "\n";
	o << "Signed: " << (i.getSigned() ? "signed" : "not signed") << "\n";
	o << "Grade to sign: " << i.getSignGrade() << "\n";
	o << "Grade to execute: " << i.getExecuteGrade();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Form::beSigned(Bureaucrat &bureaucrat) {

	if (bureaucrat.getGrade() <= this->_signGrade)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Form::getName() const {
	return (this->_name);
}

bool Form::getSigned() const {
	return (this->_signed);
}

int Form::getSignGrade() const {
	return (this->_signGrade);
}

int Form::getExecuteGrade()const {
	return (this->_executeGrade);
}



/*
** --------------------------------- EXCEPTIONS -------------------------------
*/

const char *Form::GradeTooHighException::what() const throw() {
	return ("[FORM] Grade is too hight ( < 1 )!");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("[FORM] Grade is too low ( > 150 )!");
}

/* ************************************************************************** */