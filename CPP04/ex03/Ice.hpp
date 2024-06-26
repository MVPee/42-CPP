#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Ice : public AMateria
{
	public:

		Ice();
		Ice(Ice const & src);
		~Ice();

		Ice & operator=(Ice const & rhs);
};

#endif /* ************************************************************* ICE_H */