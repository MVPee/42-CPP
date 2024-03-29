#include "ClapTrap.hpp"

int main(void) {
    ClapTrap MVP("MVP");
    ClapTrap Robot("Robot");
    ClapTrap ClapTrap("ClapTrap");

    std::cout << std::endl;

    std::cout << "---PART1---" << std::endl;
    MVP.attack("ClapTRap");
    ClapTrap.takeDamage(2);
    Robot.attack("ClapTRap");
    ClapTrap.takeDamage(42);
    ClapTrap.beRepaired(19);

    std::cout << std::endl;

    std::cout << "---PART2---" << std::endl;
    Robot.setEnergy(1);
    Robot.attack("NOBODY");
    Robot.attack("NOBODY");
    Robot.setHeal(0);
    Robot.attack("NOBODY");

    std::cout << std::endl;

    return (0);
}