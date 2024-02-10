#include "Harl.hpp"

Harl::Harl() { return ; }

Harl::~Harl() { return ; }

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n" << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]\nThis is unacceptable,\nI want to speak to the manager now.\n" << std::endl;
}

int Harl::getLevel(std::string level) {
    const char* levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < (int)(sizeof(levels) / sizeof(levels[0])); ++i) {
        if (level == levels[i]) {
            return i + 1;
        }
    }

    return -1;
}

void Harl::complain(std::string level) {

    int i = getLevel(level);
    switch(i)
    {
        case 1:
            debug();
            info();
            warning();
            error();
            break;
        case 2:
            info();
            warning();
            error();
            break;
        case 3:
            warning();
            error();
            break;
        case 4:
            error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}