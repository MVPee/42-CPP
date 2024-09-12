#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>

class Span {
	private:
		std::vector<int>	_vec;
		unsigned int		_size;

	public:
		Span();
		Span(unsigned int size);
		Span(const Span &src);
		Span &operator=(const Span &rhs);
		~Span();

		void addNumber(int number);
		void addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);
		int shortestSpan(void);
		int longestSpan(void);
};

std::ostream &operator<<(std::ostream &o, const Span &i);

#endif /* ************************************************************ SPAN_H */