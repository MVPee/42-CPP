#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

# define GREEN "\033[0;32m"
# define RED "\033[1;31m"
# define ORANGE "\033[1;33m"
# define NONE "\033[0m"

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria();
		AMateria(AMateria const & src);
		virtual ~AMateria();
		AMateria & operator=(AMateria const & rhs);

		const std::string& getType() const;
		// virtual AMateria* clone() const = 0;
		// virtual void use(ICharacter& target);
};

#endif /* ******************************************************** AMATERIA_H */