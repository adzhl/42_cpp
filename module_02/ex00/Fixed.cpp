/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:43:24 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/11 09:31:45 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _rawBits(0) { std::cout << "Default constructor called\n"; }

// Destructor
Fixed::~Fixed() { std::cout << "Destructor called\n"; }

// Copy constructor
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called\n";
    *this = other;
}

// Fixed::Fixed(const Fixed& other) : _rawBits(other._rawBits) {
//     std::cout << "Copy constructor called\n";
// }

// Fixed::Fixed(const Fixed& other) {
//     std::cout << "Copy constructor called\n";
//     this->_rawBits = other.getRawBits();
// }

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
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called\n";
    return (this->_rawBits);
}

// Setter
void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called\n";
    this->_rawBits = raw;
}
