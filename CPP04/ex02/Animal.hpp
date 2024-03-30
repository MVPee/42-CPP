#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

# define GREEN "\033[0;32m"
# define RED "\033[1;31m"
# define ORANGE "\033[1;33m"
# define NONE "\033[0m"

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(Animal const & src);
		virtual ~Animal();
		Animal& operator=(Animal const& rhs);

		virtual void makeSound(void) const = 0;

		const std::string& getType(void) const;
};

#endif /* ********************************************************** ANIMAL_H */