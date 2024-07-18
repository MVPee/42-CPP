#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>

class Base
{
	private:

	public:
		Base();
		Base( Base const & src );
		~Base();

		Base &		operator=( Base const & rhs );
};

#endif /* ************************************************************ BASE_H */