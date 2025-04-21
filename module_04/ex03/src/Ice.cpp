/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 08:45:31 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/21 10:40:10 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// Default constructor
Ice::Ice() : AMateria("ice") { std::cout << "Ice default constructor called\n"; }

// Copy constructor
Ice::Ice(const Ice& other) : AMateria(other) { std::cout << "Ice copy constructor called\n"; }

// Copy assignment operator
Ice&    Ice::operator=(const Ice& other) {
    std::cout << "Ice copy assignment operator called\n";
    if (this != &other) { AMateria::operator=(other); }
    return (*this);
}

// Destructor
Ice::~Ice() { std::cout << "Ice destructor called\n"; }

// Clone another copy itself
AMateria*   Ice::clone() const { return (new Ice()); }

// Message
void    Ice::use(ICharacter& target) {
    std::cout << GREEN << "* shoots an ice bolt at " << target.getName() << " *\n" << RESET;
}
