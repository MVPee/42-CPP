#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain() {
	std::cout << GREEN << "[ Brain ] Constructer called." << NONE << std::endl;
}

Brain::Brain(const Brain& src) {
	std::cout << GREEN << "[ Brain ] Copied constructer called." << NONE << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain() {
	std::cout << RED << "[ Brain ] Destructor called." << NONE << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &	Brain::operator=(Brain const& rhs)
{
	if ( this != &rhs )
		for (int i = 0; i < 100 ; i++)
			this->ideas[i] = rhs.ideas[i];
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */