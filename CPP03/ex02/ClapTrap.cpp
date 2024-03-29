#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap(std::string name) : name(name), health(10), energy(10), damage(0) {
	std::cout << "Constructor ClapTrap: " << name << std::endl;
}

ClapTrap::ClapTrap() : name("Default"), health(10), energy(10), damage(0) {
	std::cout << "Constructor ClapTrap: " << name << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap & src )
{
	std::cout << "Copy constructor ClapTrap called" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap(void) {
	std::cout << "Destructor ClapTrap: " << name << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap & ClapTrap::operator=( ClapTrap const &rhs )
{
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

void ClapTrap::attack(const std::string& target) {
	if (health < 1)
		std::cout << name << " is dead and can't attack anymore !" << std::endl;
	else if (energy < 1)
		std::cout << name << " don't have enought energy to attack " << target << "!" << std::endl;
	else
	{
		std::cout << name << " attack " << target << "!" << std::endl;
		energy--;
	}
}	

void ClapTrap::takeDamage(unsigned int amount) {
	if (health < 1)
		std::cout << name << " is dead and can't take damage anymore !" << std::endl;
	else
	{
		std::cout << name << " has taken " << amount << " points of damage!" << std::endl;
		health -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (health < 1)
		std::cout << name << " is dead and can't repair anymore !" << std::endl;
	else if (energy < 1)
		std::cout << name << " don't have enought energy to repair!" << std::endl;
	else {
		std::cout << name << " repair itself!" << std::endl;
		health += amount;
		energy--;
	}
}	

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string ClapTrap::getName(void) const { return (name); }
int ClapTrap::getHealth(void) const { return (health); }
int ClapTrap::getEnergy(void) const { return (energy); }
int ClapTrap::getAttack(void) const { return (damage); }

void ClapTrap::setName(std::string name) { this->name = name; }
void ClapTrap::setHealth(int n) { this->health = n; }
void ClapTrap::setEnergy(int n) { this->energy = n; }
void ClapTrap::setAttack(int n) { this->damage = n; }

/* ************************************************************************** */