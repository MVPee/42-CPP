#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

# define GREEN "\033[0;32m"
# define RED "\033[1;31m"
# define ORANGE "\033[1;33m"
# define NONE "\033[0m"

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(Brain const& src);
		~Brain();
		Brain & operator=(Brain const& rhs);
};

#endif /* *********************************************************** BRAIN_H */