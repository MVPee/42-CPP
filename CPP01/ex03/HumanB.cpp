#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
    this->weapon = NULL;
    this->name = name;
}
HumanB::~HumanB(void) {
    return ;
}

void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;
}

void HumanB::attack(void) {
    if (weapon)
        std::cout << this->name << " attacks with their " << (*this->weapon).getType() << std::endl;
}