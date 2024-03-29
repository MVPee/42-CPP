#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap(std::string name) : _name(name), _heal(10), _energy(10), _attack(0) {
	std::cout << "Constructor: " << _name << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap(void) {
	std::cout << "Destructor: " << _name << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap & ClapTrap::operator=( ClapTrap const &rhs )
{
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_heal = rhs._heal;
		this->_energy = rhs._energy;
		this->_attack = rhs._attack;
	}
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ClapTrap::attack(const std::string& target) {
	if (_heal < 1)
		std::cout << _name << " is dead and can't attack anymore !" << std::endl;
	else if (_energy < 1)
		std::cout << _name << " don't have enought energy to attack " << target << "!" << std::endl;
	else
	{
		std::cout << _name << " attack " << target << "!" << std::endl;
		_energy--;
	}
}	

void ClapTrap::takeDamage(unsigned int amount) {
	if (_heal < 1)
		std::cout << _name << " is dead and can't take damage anymore !" << std::endl;
	else
	{
		std::cout << _name << " has taken " << amount << " points of damage!" << std::endl;
		_heal -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_heal < 1)
		std::cout << _name << " is dead and can't repair anymore !" << std::endl;
	else if (_energy < 1)
		std::cout << _name << " don't have enought energy to repair!" << std::endl;
	else {
		std::cout << _name << " repair itself!" << std::endl;
		_heal += amount;
		_energy--;
	}
}	

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string ClapTrap::getName(void) const { return (_name); }
int ClapTrap::getHeal(void) const { return (_heal); }
int ClapTrap::getEnergy(void) const { return (_energy); }
int ClapTrap::getAttack(void) const { return (_attack); }

void ClapTrap::setName(std::string name) { this->_name = name; }
void ClapTrap::setHeal(int n) { this->_heal = n; }
void ClapTrap::setEnergy(int n) { this->_energy = n; }
void ClapTrap::setAttack(int n) { this->_attack = n; }

/* ************************************************************************** */