#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character(std::string name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
		inv[i] = NULL;
}

Character::Character( const Character & src )
{
	for (int i = 0; i < 4; i++)
		if (src.inv[i])
			this->inv[i] = src.inv[i];
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if(inv[i])
			delete inv[i];
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	if ( this != &rhs )
	{
		for(int i = 0; i < 4; i++)
		{
			if (this->inv[i])
				delete this->inv[i];
			if (rhs.inv[i])
				this->inv[i] = (rhs.inv[i])->clone();
		}
		name = rhs.name;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */