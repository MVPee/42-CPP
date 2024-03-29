#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	private:
		std::string _name;
		int _heal; //hit
		int _energy;
		int _attack;
	public:

		ClapTrap(std::string name);
		ClapTrap( ClapTrap const & src );
		~ClapTrap(void);

		ClapTrap & operator=( ClapTrap const & rhs );

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getName(void) const;
		int getHeal(void) const;
		int getEnergy(void) const;
		int getAttack(void) const;

		void setName(std::string name);
		void setHeal(int n);
		void setEnergy(int n);
		void setAttack(int n);
};

#endif /* ******************************************************** CLAPTRAP_H */