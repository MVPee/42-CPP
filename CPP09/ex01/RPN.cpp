#include "RPN.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RPN::RPN() {}

RPN::RPN(const RPN &src) {
	_stack = src._stack;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RPN::~RPN() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RPN &				RPN::operator=(const RPN &rhs) {
	if (this != &rhs)
		this->_stack=rhs._stack;
	return *this;
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
	else if (line == "/") {
		if (n2 == 0) {
			std::cerr << "Erreur: \"You can't divise by 0\"" << std::endl;
			exit (1);
		}
		else result = n1 / n2;
	}
	_stack.push(result);
}

void RPN::process(const std::string &input) {
	std::string line;
	std::stringstream line_stream(input);
	while(std::getline(line_stream, line, ' ')) {
		if (!line.empty()) {
            if ((line.at(0) == '-' && line.length() > 1 && std::isdigit(line.at(1))) || std::isdigit(line.at(0))) {
                try {
					#ifdef __APPLE__
                    	_stack.push(std::stoi(line));
					#else
						_stack.push(atoi(line.c_str()));
					#endif
                }
                catch (const std::invalid_argument&) {
                    std::cerr << "Erreur: \"" << line << "\"" << std::endl;
                    return;
                }
            }
            else if (line == "+" || line == "-" || line == "*" || line == "/")
                processMethod(line);
			else {
				std::cerr << "Erreur: \"" << line << "\"" << std::endl;
				return ;
			}
        }
	}
	std::cout << "[ ";
	while(!_stack.empty()) {
		std::cout << _stack.top() << " ";
		_stack.pop();
	}
	std::cout << "]" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */