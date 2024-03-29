#include "Fixed.hpp"

/* CONSTRUCTOR */

Fixed::Fixed(void) : value(0){
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
    //std::cout << "Copy constructor called" << std::endl;
    this->value = fixed.getRawBits();
}

Fixed::Fixed(const int integer) {
    //std::cout << "Int constructor called" << std::endl;
    this->value = integer << bit;
}

Fixed::Fixed(const float floating) {
    //std::cout << "Float constructor called" << std::endl;
    this->value = roundf(floating * (1 << this->bit));
}

Fixed & Fixed::operator=(const Fixed &fixed) {
    //std::cout << "Copy assignment operator called" << std::endl;
    this->value = fixed.getRawBits();
    return (*this);
}


/* DESCTRUCTOR */

Fixed::~Fixed(void) {
    //std::cout << "Destructor called" << std::endl;
}


/* GETTER */

int Fixed::getRawBits(void) const {
    //std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}

int Fixed::getBits(void) const {
    return (this->bit);
}

/* SETTER */

void Fixed::setRawBits(int const raw) {
    //std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}


/* METHODS */

float Fixed::toFloat(void) const {
    return ((float)this->getRawBits() / (1 << this->bit));
}

int Fixed::toInt(void) const {
    return (this->getRawBits() >> this->bit);
}

Fixed& Fixed::min(Fixed &first, Fixed &second) {
    if (first <= second)
        return (first);
    return (second);
}

Fixed Fixed::min(Fixed const &first, Fixed const &second) {
    if (first <= second)
        return (Fixed(first));
    return (Fixed(second));
}

Fixed& Fixed::max(Fixed &first, Fixed &second) {
    if (first >= second)
        return (first);
    return (second);
}

Fixed Fixed::max(Fixed const &first, Fixed const &second) {
    if (first >= second)
        return (Fixed(first));
    return (Fixed(second));
}


/* OPERATOR */

std::ostream& operator<<(std::ostream &os, Fixed const &fixed) {
	os << fixed.toFloat();
	return (os);
}

bool Fixed::operator > (Fixed const &fixed) const {
    return (this->value > fixed.getRawBits());
}

bool Fixed::operator < (Fixed const &fixed) const {
    return (this->value < fixed.getRawBits());
}

bool Fixed::operator >= (Fixed const &fixed) const {
    return (this->value >= fixed.getRawBits());
}

bool Fixed::operator <= (Fixed const &fixed) const {
    return (this->value <= fixed.getRawBits());
}

bool Fixed::operator == (Fixed const &fixed) const {
    return (this->value <= fixed.getRawBits());
}

bool Fixed::operator != (Fixed const &fixed) const {
    return (this->value <= fixed.getRawBits());
}

Fixed Fixed::operator + (Fixed const &fixed) const {
    return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator - (Fixed const &fixed) const {
    return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator * (Fixed const &fixed) const {
    return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator / (Fixed const &fixed) const {
    if (fixed.toFloat() == 0) {
        std::cout << "You can't divise by 0" << std::endl;
        return (Fixed(this->toFloat()));
    }
    return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed& Fixed::operator++(void) {
    this->value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed old = *this;
    ++(*this);
    return old;
}

Fixed& Fixed::operator--(void) {
    this->value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed old = *this;
    --(*this);
    return old;
}
