#include "Zombie.hpp"

Zombie::Zombie(void) { 
    this->name = "NONE";
    std::cout << "Constructor: " << this->name << std::endl;
}

Zombie::Zombie(std::string name) { 
    this->name = name;
    std::cout << "Constructor: " << this->name << std::endl;
}

Zombie::~Zombie(void) {
    std::cout << "Destructor: " << this->name << std::endl;
}

void Zombie::annonce(void) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
    this->name = name;
}