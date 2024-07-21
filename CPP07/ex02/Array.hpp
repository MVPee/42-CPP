#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <stdexcept>

template <typename T>
class Array
{
	private:
		T 		*_array;
		size_t	_size;
	public:

		Array();
		Array( Array<T> const & src );
		Array(size_t size);
		~Array();
		Array &		operator=( Array<T> const & rhs );

		T &operator[](size_t index);

		size_t size() const;
};
#include "Array.cpp"

#endif /* *********************************************************** ARRAY_H */