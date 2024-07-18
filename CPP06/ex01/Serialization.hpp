#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <iostream>
# include <string>
# include <stdint.h>

typedef struct s_data {
	int value;
} Data;

class Serialization {
	private:
		Serialization();
		Serialization( Serialization const & src );
	public:
		~Serialization();
		Serialization &		operator=( Serialization const & rhs );

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

std::ostream &			operator<<( std::ostream & o, Serialization const & i );

#endif /* *************************************************** SERIALIZATION_H */