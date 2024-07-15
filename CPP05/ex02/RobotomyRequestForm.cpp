# include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("Default") {
    std::cout << GREEN << "[ RobotomyRequestForm ] Default constructor called." << NONE << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << GREEN << "[ RobotomyRequestForm " + this->getName() + " ] Constructor called." << NONE << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src)
    : AForm(src), _target(src._target) {
    std::cout << GREEN << "[ RobotomyRequestForm " + this->getName() + " ] Copy constructor called." << NONE << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << RED << "[ RobotomyRequestForm " + this->getName() + " ] Destructor called." << NONE << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm& RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs ) {
	if ( this != &rhs )
		this->_signed = rhs.getSigned();
	return *this;
}

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &i) {
    o << static_cast<AForm const &>(i); // Call the base class operator <<
    return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    checkExecution(executor);
    std::cout << "* Drilling noises *" << std::endl;
    srand(time(0));
    if (rand() % 2 == 0)
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy of " << this->_target << " failed." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */