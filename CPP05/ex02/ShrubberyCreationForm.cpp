# include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("Default") {
    std::cout << GREEN << "[ ShrubberyCreationForm ] Default constructor called." << NONE << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << GREEN << "[ ShrubberyCreationForm " + this->getName() + " ] Constructor called." << NONE << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
    : AForm(src), _target(src._target) {
    std::cout << GREEN << "[ ShrubberyCreationForm " + this->getName() + " ] Copy constructor called." << NONE << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << RED << "[ ShrubberyCreationForm " + this->getName() + " ] Destructor called." << NONE << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm& ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs ) {
	if ( this != &rhs )
		this->_signed = rhs.getSigned();
	return *this;
}

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &i) {
    o << static_cast<AForm const &>(i);
    return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    checkExecution(executor);
    std::ofstream ofs((_target + "_shrubbery").c_str());
    ofs << "       /-\\\n"
        << "    /      \\\n"
        << " /            \\\n"
        << "{              }\n"
        << " \\            /\n"
        << "       | |\n"
        << "       | |\n"
        << "       | |";
    ofs.close();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */