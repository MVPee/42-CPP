#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal() {
	std::cout << GREEN << "[ Animal ] Constructer called." << NONE << std::endl;
	this->type = "NONE";
}

Animal::Animal(const Animal& src) {
	std::cout << GREEN << "[ Animal ] Copied constructer called." << NONE << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal() {
	std::cout << RED << "[ Animal ] Destructor called." << NONE << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal& Animal::operator=( Animal const& rhs ) {
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Animal::makeSound(void) const {
	std::cout << ORANGE << this->type << ": This animal don't have sound?!" << NONE << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Animal::getType(void) const {
	return (this->type);
}

/* ************************************************************************** */