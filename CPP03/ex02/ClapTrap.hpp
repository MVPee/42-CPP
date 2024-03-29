#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	protected:
		std::string name;
		int health;
		int energy;
		int damage;
	public:

		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap( ClapTrap const & src );
		~ClapTrap(void);

		ClapTrap & operator=( ClapTrap const & rhs );

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getName(void) const;
		int getHealth(void) const;
		int getEnergy(void) const;
		int getAttack(void) const;

		void setName(std::string name);
		void setHealth(int n);
		void setEnergy(int n);
		void setAttack(int n);
};

#endif /* ******************************************************** CLAPTRAP_H */