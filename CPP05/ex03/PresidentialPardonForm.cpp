# include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), _target("Default") {
    std::cout << GREEN << "[ PresidentialPardonForm ] Default constructor called." << NONE << std::endl;
}


PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {
    std::cout << GREEN << "[ PresidentialPardonForm " + this->getName() + " ] Constructor called." << NONE << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src)
    : AForm(src), _target(src._target) {
    std::cout << GREEN << "[ PresidentialPardonForm " + this->getName() + " ] Copy constructor called." << NONE << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << RED << "[ PresidentialPardonForm " + this->getName() + " ] Destructor called." << NONE << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm& PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs ) {
	if ( this != &rhs )
		this->_signed = rhs.getSigned();
	return *this;
}

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &i) {
    o << static_cast<AForm const &>(i);
    return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    checkExecution(executor);
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */