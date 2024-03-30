#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog() {
	std::cout << GREEN << "[ Dog ] Constructer called." << NONE << std::endl;
	this->brain = new Brain();
	this->type = "Dog";
}

Dog::Dog(const Dog& src) : Animal(src){
	std::cout << GREEN << "[ Dog ] Copied constructer called." << NONE << std::endl;
	this->type = src.type;
	this->brain = new Brain(*src.brain);
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog() {
	delete this->brain;
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