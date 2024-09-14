#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <fstream>
# include <sstream>
# include <string>
# include <cstdlib>

class RPN {
	private:
		std::stack<int> _stack;

		RPN(const RPN &src);
		RPN &operator=(const RPN &rhs);
	public:
		RPN();
		~RPN();

		void process(const std::string &input);
		void processMethod(const std::string &line);
};

std::ostream &operator<<(std::ostream &o, const RPN &i);

#endif /* ************************************************************* RPN_H */