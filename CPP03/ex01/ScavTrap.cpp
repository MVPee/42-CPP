#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap(std::string name){
	this->name = name;
	this->health = 100;
	this->energy = 50;
	this->damage = 20;
	std::cout << "Constructor ScavTrap: " << name << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap & src ) : ClapTrap(src){
	std::cout << "Copy constructor ScavTrap called" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap() {
	std::cout << "Destructor ScavTrap: " << name << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap & ScavTrap::operator=( ScavTrap const & rhs ) {
	if (this != &rhs) {
		this->name = rhs.name;
		this->health = rhs.health;
		this->energy = rhs.energy;
		this->damage = rhs.damage;
	}
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ScavTrap::guardGate(void) const {
	std::cout << name << " is now in Gate Keeper mode!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (health < 1)
		std::cout << name << " is dead and can't Scav attack anymore !" << std::endl;
	else if (energy < 1)
		std::cout << name << " don't have enought energy to Scav attack " << target << "!" << std::endl;
	else
	{
		std::cout << name << " Scav attack " << target << "!" << std::endl;
		energy--;
	}
}

/* ************************************************************************** */