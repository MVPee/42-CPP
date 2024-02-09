#include "Weapon.hpp"

Weapon::Weapon(void) {
    this->type = "default";
    return ;
}

Weapon::Weapon(std::string name) {
    this->type = name;
    return ;
}

Weapon::~Weapon(void) {
    return ;
}

const std::string& Weapon::getType(void) const {
    return (this->type);
}

void Weapon::setType(std::string name) {
    this->type = name;
}