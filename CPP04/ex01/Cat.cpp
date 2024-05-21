#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat() {
	std::cout << GREEN << "[ Cat ] Constructer called." << NONE << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& src) : Animal(src){
	std::cout << GREEN << "[ Cat ] Copied constructer called." << NONE << std::endl;
	this->type = src.type;
	this->brain = new Brain(*src.brain);
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat() {
	delete this->brain;
	std::cout << RED << "[ Cat ] Destructor called." << NONE << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat& Cat::operator=( Cat const& rhs ) {
	if (this != &rhs)
		this->type = rhs.getType();
		this->brain = new Brain(*rhs.brain);
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