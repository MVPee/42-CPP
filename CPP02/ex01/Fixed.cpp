#include "Fixed.hpp"

/* CONSTRUCTOR */

Fixed::Fixed(void) : value(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
    std::cout << "Copy constructor called" << std::endl;
    this->value = fixed.getRawBits();
}

Fixed::Fixed(const int integer) {
    std::cout << "Int constructor called" << std::endl;
    this->value = integer << bit;
}

Fixed::Fixed(const float floating) {
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(floating * (1 << this->bit));
}

Fixed & Fixed::operator=(const Fixed &fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->value = fixed.getRawBits();
    return (*this);
}


/* DESCTRUCTOR */

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
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
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}


/* OTHERS */

float Fixed::toFloat(void) const {
    return ((float)this->getRawBits() / (1 << this->bit));
}

int Fixed::toInt(void) const {
    return (this->getRawBits() >> this->bit);
}

std::ostream& operator<<(std::ostream &os, Fixed const &fixed) {
	os << fixed.toFloat();
	return (os);
}