#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog() {
	std::cout << GREEN << "[ Dog ] Constructer called." << NONE << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog& src) : Animal(src){
	std::cout << GREEN << "[ Dog ] Copied constructer called." << NONE << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog() {
	std::cout << RED << "[ Dog ] Destructor called." << NONE << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog& Dog::operator=( Dog const& rhs ) {
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Dog::makeSound(void) const {
	std::cout << ORANGE << this->type << ": WOOF!" << NONE << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */