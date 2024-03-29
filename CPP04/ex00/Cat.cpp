#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat() {
	std::cout << GREEN << "[ Cat ] Constructer called." << NONE << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& src) : Animal(src){
	std::cout << GREEN << "[ Cat ] Copied constructer called." << NONE << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat() {
	std::cout << RED << "[ Cat ] Destructor called." << NONE << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat& Cat::operator=( Cat const& rhs ) {
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Cat::makeSound(void) const {
	std::cout << ORANGE << this->type << ": MIAUWW!" << NONE << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */