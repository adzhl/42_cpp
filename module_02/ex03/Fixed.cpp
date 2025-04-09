/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 07:55:57 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/09 07:56:01 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _rawBits(0) {}

// Int constructor
// shifting 8 bits to the left: 2^8 = 256
// value * 256 = stored value
// ensures integer part is preserved in the higher bits & 
// fractional part reserved in the lower bits
Fixed::Fixed(const int value) : _rawBits(value << _fractionalBits) {}

// Float constructor
// 1 << _fractionalBits(8) = 2^8 = 256
// value * 256 = stored value rounded to the nearest integer
Fixed::Fixed(const float value) : _rawBits(roundf(value * (1 << _fractionalBits))) {}

// Destructor
Fixed::~Fixed() {}

// Copy constructor
Fixed::Fixed(const Fixed& other) { *this = other; }

// Copy assignment operator overload
// (this != &other) : check for self-assignment
//                  : avoid accidentally deleting own data
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        this->_rawBits = other.getRawBits();
    }
    return (*this);
}

// Getter
int Fixed::getRawBits(void) const { return (this->_rawBits); }

// Setter
void Fixed::setRawBits(int const raw) { this->_rawBits = raw; }

// convert Fixed-point number to float
float   Fixed::toFloat(void) const { return ((float)_rawBits / (1 << _fractionalBits)); }

// convert Fixed-point number to int
int     Fixed::toInt(void) const { return (_rawBits >> _fractionalBits); }

// toFloat() is used to preserve the fractional part of the fixed-point number
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return (os);
}

// Comparison operators
bool    Fixed::operator>(const Fixed& other) const { return (this->_rawBits > other.getRawBits()); }

bool    Fixed::operator<(const Fixed& other) const { return (this->_rawBits < other.getRawBits()); }

bool    Fixed::operator>=(const Fixed& other) const { return (this->_rawBits >= other.getRawBits()); }

bool    Fixed::operator<=(const Fixed& other) const { return (this->_rawBits <= other.getRawBits()); }

bool    Fixed::operator==(const Fixed& other) const { return (this->_rawBits == other.getRawBits()); }

bool    Fixed::operator!=(const Fixed& other) const { return (this->_rawBits != other.getRawBits()); }

// Arithmetic operators
Fixed  Fixed::operator+(const Fixed& other) const { return (this->toFloat() + other.toFloat()); }

Fixed  Fixed::operator-(const Fixed& other) const { return (this->toFloat() - other.toFloat()); }

Fixed  Fixed::operator*(const Fixed& other) const { return (this->toFloat() * other.toFloat()); }

Fixed  Fixed::operator/(const Fixed& other) const { return (this->toFloat() / other.toFloat()); }

// Increment/Decrement
Fixed&  Fixed::operator++() {
    this->_rawBits++;
    return (*this);
}

Fixed  Fixed::operator++(int) {
    Fixed temp = *this;
    this->_rawBits++;
    return (temp);
}

Fixed&  Fixed::operator--() {
    this->_rawBits--;
    return (*this);
}

Fixed  Fixed::operator--(int) {
    Fixed temp = *this;
    this->_rawBits--;
    return (temp);
}

// Overloaded member functions
// Function overloading : same function name with different parameter types
//                      : C++ treats them as two different functions
// Static functions     : Not tied to an instance / cannot use 'this' pointer
//                      : Can be called without needing an object -> Fixed::min(a, b) instead of a.min(b)
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}
