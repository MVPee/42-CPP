#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap(std::string name){
	this->name = name;
	this->health = 100;
	this->energy = 100;
	this->damage = 30;
	std::cout << "Constructor FragTrap: " << name << std::endl;
}

FragTrap::FragTrap( const FragTrap & src ) : ClapTrap(src){
	std::cout << "Copy constructor FragTrap called" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap() {
	std::cout << "Destructor FragTrap: " << name << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap & FragTrap::operator=( FragTrap const & rhs ) {
	if ( this != &rhs ) {
		this->name = rhs.name;
		this->health = rhs.health;
		this->energy = rhs.energy;
		this->damage = rhs.damage;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void FragTrap::highFivesGuys(void) const {
	std::cout << name << " do a positive high fives to you in the standart output!" << std::endl;
}

/* ************************************************************************** */