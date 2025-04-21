/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 08:12:40 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/21 10:15:01 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Default constructor
AMateria::AMateria() : _type("Unknown") { std::cout << "AMateria default constructor called\n"; }

// Custom constructor
AMateria::AMateria(std::string const& type) : _type(type) { std::cout << "AMateria constructor called for type " << this->_type << '\n'; }

// Copy constructor
AMateria::AMateria(const AMateria& other) : _type(other.getType()) { std::cout << "AMateria copy constructor called\n"; }

// Copy assignment operator
AMateria&   AMateria::operator=(const AMateria& other) {
    std::cout << "AMateria copy assignment operator called\n";
    if (this != &other) { this->_type = other.getType(); }
    return (*this);
}

// Destructor
AMateria::~AMateria() { std::cout << "AMateria destructor called\n"; }

// Getter
std::string const&  AMateria::getType() const { return (this->_type); }

void    AMateria::use(ICharacter& target) { std::cout << "AMateria is used on " << target.getName() << '\n'; }
