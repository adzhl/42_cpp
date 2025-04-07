/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:59:18 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/07 13:58:56 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _rawBits(0) { std::cout << "Default constructor called\n"; }

// Int constructor
// shifting 8 bits to the left: 2^8 = 256
// value * 256 = stored value
// ensures integer part is preserved in the higher bits & 
// fractional part reserved in the lower bits
Fixed::Fixed(const int value) : _rawBits(value << _fractionalBits) { std::cout << "Int constructor called\n"; }

// Float constructor
// 1 << _fractionalBits(8) = 2^8 = 256
// value * 256 = stored value rounded to the nearest integer
Fixed::Fixed(const float value) : _rawBits(roundf(value * (1 << _fractionalBits))) { std::cout << "Float constructor called\n"; }

// Destructor
Fixed::~Fixed() { std::cout << "Destructor called\n"; }

// Copy constructor
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called\n";
    *this = other;
}

// Copy assignment operator overload
// (this != &other) : check for self-assignment
//                  : avoid accidentally deleting own data
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called\n";
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
