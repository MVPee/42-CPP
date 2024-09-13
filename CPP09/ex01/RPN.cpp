#include "RPN.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RPN::RPN() {
}

RPN::RPN(const RPN &src) {
	_stack = src._stack;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RPN::~RPN() {
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RPN &				RPN::operator=(const RPN &rhs) {
	if (this != &rhs)
		this->_stack=rhs._stack;
	return *this;
}

std::ostream &			operator<<(std::ostream & o, const RPN &i) {
	(void)i;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void RPN::processMethod(const std::string &line) {
	int n1, n2, result;
	if (_stack.empty())
		n2 = 0;
	else {
		n2 = _stack.top();
		_stack.pop();
	}
	if (_stack.empty())
		n1 = 0;
	else {
		n1 = _stack.top();
		_stack.pop();
	}
	if (line == "+") result = n1 + n2;
	else if (line == "-") result = n1 - n2;
	else if (line == "*") result = n1 * n2;
	else if (line == "/") result = n1 / n2;
	_stack.push(result);
}

void RPN::process(const std::string &input) {
	std::string line;
	std::stringstream line_stream(input);
	while(std::getline(line_stream, line, ' ')) {
		std::cout << line << std::endl;
		if (std::isdigit(line.at(0)))
			_stack.push(atoi(line.c_str()));
		else
			processMethod(line);
	}
	std::cout << _stack.top() << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */