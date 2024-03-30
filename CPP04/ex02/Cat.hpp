#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat(Cat const & src);
		~Cat();
		Cat& operator=(Cat const& rhs);

		virtual void makeSound(void) const;
};

#endif /* ********************************************************** CAT_H */