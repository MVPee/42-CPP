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

static bool isNumber(const std::string& literal) {
    std::string::size_type i = 0;
    bool hasDigit = false;
    bool hasDot = false;

    if (literal[i] == '-')
        ++i;

    for (; i < literal.length(); ++i) {
        if (literal[i] == '.') {
            if (hasDot)
				return false;
            hasDot = true;
        }
		else if (!std::isdigit(literal[i]))
            return false;
        else
            hasDigit = true;
    }
    return hasDigit;
}

static void charConvert(const std::string& literal) {
    if (literal == "nan" || literal == "nanf" ||
        literal == "-inf" || literal == "inf" ||
        literal == "-inff" || literal == "inff") {
		std::cout << "int: impossible" << std::endl;
	}
    else if (!isNumber(literal)) {
        if (literal.length() == 1)
            std::cout << "char: '" << literal << "'" << std::endl;
        else
            std::cout << "char: '*'" << std::endl;
    } 
	else {
        int num = atoi(literal.c_str());
        if (num > 31 && num < 127)
            std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
}

static void intConvert(const std::string& literal) {
    char *end;
    float num = strtof(literal.c_str(), &end);

    if (!isNumber(literal)) {
        std::cout << "int: impossible" << std::endl;
    }
    else if (*end != '\0' && *end != 'f' && *end != 'F')
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(num) << std::endl;
}

static void floatConvert(const std::string& literal) {
    char *end;
    float num = strtof(literal.c_str(), &end);

    if (*end != '\0' && *end != 'f' && *end != 'F')
        std::cout << "float: impossible" << std::endl;
    else
    	std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
}

static void doubleConvert(const std::string& literal) {
    char *end;
    float num = strtof(literal.c_str(), &end);

    if (*end != '\0' && *end != 'f' && *end != 'F')
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(num) << std::endl;
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