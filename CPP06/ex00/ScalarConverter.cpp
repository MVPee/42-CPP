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
    std::string::size_type i = 0;
    bool hasDigit = false;
    bool hasDot = false;

    if (literal == "nan" || literal == "nanf" ||
        literal == "-inf" || literal == "inf" ||
        literal == "-inff" || literal == "inff") {
		return (true);
	}

    if (literal[i] == '-' || literal[i] == '+')
        ++i;

    for (; i < literal.length(); ++i) {
        if (literal[i] == '.') {
            if (hasDot)
				return (false);
            hasDot = true;
        }
        else if ((literal[i] == 'f' || literal[i] == 'F') && i == literal.length() - 1 && i != 0)
            return (true);
		else if (!std::isdigit(literal[i]))
            return (false);
        else
            hasDigit = true;
    }
    return (hasDigit);
}

t_type getType(const std::string& literal) {
    if (isNumber(literal)) {
        if (literal.find('.') != std::string::npos || \
            literal.find('f') != std::string::npos || \
            literal.find('F') != std::string::npos) {
            if (literal.find('f') != std::string::npos || literal.find('F') != std::string::npos)
                return FLOAT;
            else
                return DOUBLE;
        }
        return INT;
    }
    return CHAR;
}

static void getChar(std::string literal, t_type type) {
    if (type == CHAR) {
        if (literal.length() > 1)
            std::cout << "char: '*'" << std::endl;
        else
            std::cout << "char: " << literal << std::endl;
    }
    else if (literal == "nan" || literal == "nanf" ||
        literal == "-inf" || literal == "inf" ||
        literal == "-inff" || literal == "inff") {
		std::cout << "char: impossible" << std::endl;
	}
    else if (type == INT) {
        int temp = atoi(literal.c_str());
        if (temp > 31 && temp < 127)
            std::cout << "char: '" << static_cast<char>(temp) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
        std::cout << "char: '*'" << std::endl;
}

static void getInt(std::string literal, t_type type) {
    if (type == CHAR)
        std::cout << "int: impossible" << std::endl;
    else if (literal == "nan" || literal == "nanf" ||
        literal == "-inf" || literal == "inf" ||
        literal == "-inff" || literal == "inff") {
		std::cout << "int: impossible" << std::endl;
	}
    else {
        int temp = atoi(literal.c_str());
        std::cout << "int: " << temp << std::endl;
    }
}

static void getFloat(std::string literal, t_type type) {
    if (type == CHAR)
        std::cout << "float: impossible" << std::endl;
    else {
        char *end;
        float num = strtof(literal.c_str(), &end);
        if (*end != '\0' && *end != 'f' && *end != 'F')
            std::cout << "float: impossible" << std::endl;
        else
            std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
    }
}

static void getDouble(std::string literal, t_type type) {
    if (type == CHAR)
        std::cout << "double: impossible" << std::endl;
    else {
        char *end;
        float num = strtof(literal.c_str(), &end);
        if (*end != '\0' && *end != 'f' && *end != 'F')
            std::cout << "double: impossible" << std::endl;
        else
            std::cout << "double: " << static_cast<double>(num) << std::endl;
    }
}
void ScalarConverter::convert(std::string literal) {
	std::cout << "Default: " << literal << std::endl;

    t_type type = getType(literal);
    if (type == INT)
        std::cout << "Type: INT" << std::endl;
    if (type == FLOAT)
        std::cout << "Type: FLOAT" << std::endl;
    if (type == DOUBLE)
        std::cout << "Type: DOUBLE" << std::endl;
    if (type == CHAR)
        std::cout << "Type: CHAR" << std::endl;
    std::cout << std::endl;

    getChar(literal, type);
    getInt(literal, type);
    getFloat(literal, type);
    getDouble(literal, type);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */