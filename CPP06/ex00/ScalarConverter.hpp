#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cctype>
# include <string>

typedef enum e_type {
	CHAR = 1,
	INT = 2,
	FLOAT = 3,
	DOUBLE = 4
}	t_type;

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter( ScalarConverter const & src );
	public:
		~ScalarConverter();

		static void convert(std::string literal);

		ScalarConverter &		operator=( ScalarConverter const & rhs );
};

#endif /* ************************************************* SCALARCONVERTER_H */