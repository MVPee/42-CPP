#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(Dog const & src);
		~Dog();
		Dog& operator=(Dog const& rhs);

		virtual void makeSound(void) const;
};

#endif /* ********************************************************** DOG_H */