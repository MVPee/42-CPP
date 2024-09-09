#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span() : _size(5){
}
Span::Span(unsigned int size) : _size(size){}

Span::Span(const Span &src) {
	_size = src._size;
	_list = src._list;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span() {
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &Span::operator=(const Span &rhs) {
	if ( this != &rhs )
		_list = rhs._list;
	return *this;
}

std::ostream &operator<<(std::ostream &o, const Span &i) {
	(void)i;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Span::addNumber(int number) {
	if (_list.size() < _size)
		_list.push_back(number);
	else
		throw std::length_error("Span is full...");
};

int Span::shortestSpan(void) {
    if (_list.size() < 2)
        throw std::length_error("Span needs at least two elements for this function...");

    std::list<int> copy = _list;
    std::list<int>::const_iterator start;
    std::list<int>::const_iterator next;

    copy.sort();
    start = copy.begin();
    next = ++copy.begin();
    int shortest = *next - *start;
    while (next != copy.end()) {
        ++start;
        ++next;
        if (next != copy.end() && (*next - *start) < shortest)
            shortest = *next - *start;
    }

    return (shortest);
}

int Span::longestSpan(void) {
	if (_list.size() < 2)
		throw std::length_error("Span need two elements for this function...");
	std::list<int>::const_iterator start = _list.begin();
    std::list<int>::const_iterator end = _list.end();
	return (*std::max_element(start, end) - *std::min_element(start, end));
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */