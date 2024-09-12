#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span() : _size(5){
}
Span::Span(unsigned int size) : _size(size){}

Span::Span(const Span &src) {
	_size = src._size;
	_vec = src._vec;
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
		_vec = rhs._vec;
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
	if (_vec.size() < _size)
		_vec.push_back(number);
	else
		throw std::length_error("Span is full...");
}

void Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end) {
    if (_vec.size() + std::distance(start, end) > _size)
        throw std::out_of_range("out of range...");
    _vec.assign(start, end);
}

int Span::shortestSpan(void) {
    if (_vec.size() < 2)
        throw std::length_error("need two elements for this function");
    std::vector<int> _copy(_vec);
    std::sort(_copy.begin(), _copy.end());
    int result = INT_MAX;
    for (size_t i = 0; i < _copy.size() - 1; i++) {
        if (_copy[i + 1] - _copy[i] < result)
            result = _copy[i + 1] - _copy[i];
    }
    return (result);
}

int Span::longestSpan(void) {
    if (_vec.size() < 2)
        throw std::length_error("need two elements for this function");
    std::vector<int> _copy(_vec);
    std::sort(_copy.begin(), _copy.end());
    return _copy.back() - _copy.front();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */