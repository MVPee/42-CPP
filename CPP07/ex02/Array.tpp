#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(Array const & src) : _array(NULL), _size(0) {
    *this = src;
}

template <typename T>
Array<T>::Array(size_t size) : _array(NULL), _size(size) {
    this->_array = new T[this->_size]();
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

template <typename T>
Array<T>::~Array() {
	if (this->_array)
    	delete[] this->_array;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

template <typename T>
Array<T> & Array<T>::operator=(Array const & rhs) {
    if (this != &rhs) {
		if (this->_array)
        	delete[] this->_array;
        this->_size = rhs._size;
        this->_array = new T[this->_size];
        for (size_t i = 0; i < this->_size; ++i) {
            this->_array[i] = rhs._array[i];
        }
    }
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

template <typename T>
T &Array<T>::operator[](size_t index) {
    if (index >= this->_size) {
        throw std::out_of_range("Index out of range");
    }
    return this->_array[index];
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

template <typename T>
size_t Array<T>::size() const {
    return _size;
}

/* ************************************************************************** */

#endif