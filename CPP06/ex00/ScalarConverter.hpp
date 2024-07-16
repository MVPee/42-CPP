#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cctype>
# include <string>

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