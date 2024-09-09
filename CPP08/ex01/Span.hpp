#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <list>

class Span {
	private:
		std::list<int>	_list;
		unsigned int	_size;

	public:
		Span();
		Span(unsigned int size);
		Span(const Span &src);
		Span &operator=(const Span &rhs);
		~Span();

		void addNumber(int number);
		int shortestSpan(void);
		int longestSpan(void);
};

std::ostream &operator<<(std::ostream &o, const Span &i);

#endif /* ************************************************************ SPAN_H */