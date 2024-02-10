#include "Harl.hpp"

Harl::Harl() {
    this->levelFunctions[0].level = "DEBUG";
    this->levelFunctions[0].func = &Harl::debug;

    this->levelFunctions[1].level = "INFO";
    this->levelFunctions[1].func = &Harl::info;

    this->levelFunctions[2].level = "WARNING";
    this->levelFunctions[2].func = &Harl::warning;

    this->levelFunctions[3].level = "ERROR";
    this->levelFunctions[3].func = &Harl::error;
}

Harl::~Harl() { return ; }

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!" << std::endl;
}
void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error( void )
{
	std::cout << "This is unacceptable,\nI want to speak to the manager now" << std::endl;
}

void Harl::complain(std::string level) {
    bool complained = false;

    const size_t size = sizeof(this->levelFunctions) / sizeof(this->levelFunctions[0]);
    for (size_t i = 0; i < size; ++i) {
        if (level == this->levelFunctions[i].level) {
            (this->*(this->levelFunctions[i].func))();
            complained = true;
            break;
        }
    }
    if (!complained)
        std::cout << "[Nothing] Stop it! Get some help!" << std::endl;
}
