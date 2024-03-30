#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat() {
	std::cout << GREEN << "[ WrongCat ] Constructer called." << NONE << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src){
	std::cout << GREEN << "[ WrongCat ] Copied constructer called." << NONE << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat() {
	std::cout << RED << "[ WrongCat ] Destructor called." << NONE << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat& WrongCat::operator=( WrongCat const& rhs ) {
	if (this != &rhs)
		this->type = rhs.getType();
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void WrongCat::makeSound(void) const {
	std::cout << ORANGE << this->type << ": MIAUWW!" << NONE << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */