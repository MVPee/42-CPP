#include "ScalarConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter( const ScalarConverter & src ) {
	(void) src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScalarConverter::~ScalarConverter() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScalarConverter& ScalarConverter::operator=( ScalarConverter const & rhs ) {
	(void) rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

static bool isNumber(std::string literal) {
	for (std::string::size_type i = 0; i < literal.length(); ++i) {
		if (!std::isdigit(literal[i]))
			return (false);
	}
	return (true);
}

static void charConvert(std::string literal) {
	if (!isNumber(literal)) {
		if (literal.length() == 1)
			std::cout << "char: " << literal << std::endl;
		else
			std::cout << "char: '*'" << std::endl;
	}
	else {
		if (atoi(literal.c_str()) > 31 && atoi(literal.c_str()) < 127)
			std::cout << "char: '" << static_cast<char>(atoi(literal.c_str())) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
}

static void intConvert(std::string literal) {
	if (!isNumber(literal)) {
		std::cout << "int: impossible" << std::endl;
	}
	else {
		std::cout << "int: " << atoi(literal.c_str()) << std::endl;
	}
}

static void floatConvert(std::string literal) {
	if (!isNumber(literal)) {
		std::cout << "float: impossible" << std::endl;
	}
	else {
		std::cout << "float: " << atoi(literal.c_str()) << ".0f" << std::endl;
	}
}

static void doubleConvert(std::string literal) {
	if (!isNumber(literal)) {
		std::cout << "double: impossible" << std::endl;
	}
	else {
		std::cout << "double: " << atoi(literal.c_str()) << ".0" << std::endl;
	}
}

void ScalarConverter::convert(std::string literal) {
	std::cout << "Default: " << literal << std::endl;
	std::cout << std::endl;
	charConvert(literal);
	intConvert(literal);
	floatConvert(literal);
	doubleConvert(literal);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */