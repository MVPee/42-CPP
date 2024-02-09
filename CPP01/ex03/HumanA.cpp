#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : weapon(weapon){
    this->name = name;
    this->weapon = weapon;
    return ;
}
HumanA::~HumanA(void) { return ; }

void HumanA::setWeapon(Weapon& weapon) {
    this->weapon = weapon;
}

void HumanA::attack(void) {
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}