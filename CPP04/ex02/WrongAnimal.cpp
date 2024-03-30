#include "WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal() {
	std::cout << GREEN << "[ WrongAnimal ] Constructer called." << NONE << std::endl;
	this->type = "NONE";
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) {
	std::cout << GREEN << "[ WrongAnimal ] Copied constructer called." << NONE << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal() {
	std::cout << RED << "[ WrongAnimal ] Destructor called." << NONE << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal& WrongAnimal::operator=( WrongAnimal const& rhs ) {
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void WrongAnimal::makeSound(void) const {
	std::cout << ORANGE << this->type << ": This wronganimal don't have sound?!" << NONE << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string WrongAnimal::getType(void) const {
	return (this->type);
}

/* ************************************************************************** */