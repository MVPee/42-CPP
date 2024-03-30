#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

# define GREEN "\033[0;32m"
# define RED "\033[1;31m"
# define ORANGE "\033[1;33m"
# define NONE "\033[0m"

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const & src);
		virtual ~WrongAnimal();
		WrongAnimal& operator=(WrongAnimal const& rhs);

		void makeSound(void) const;

		std::string getType(void) const;
};

#endif /* ********************************************************** WRONGANIMAL_H */