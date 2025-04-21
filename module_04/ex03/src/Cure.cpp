/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 08:59:03 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/21 10:40:24 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// Default constructor
Cure::Cure() : AMateria("cure") { std::cout << "Cure default constructor called\n"; }

// Copy constructor
Cure::Cure(const Cure& other) : AMateria(other) { std::cout << "Cure copy constructor called\n"; }

// Copy assignment operator
Cure&    Cure::operator=(const Cure& other) {
    std::cout << "Cure copy assignment operator called\n";
    if (this != &other) { AMateria::operator=(other); }
    return (*this);
}

// Destructor
Cure::~Cure() { std::cout << "Cure destructor called\n"; }

// Clone another copy itself
AMateria*   Cure::clone() const { return (new Cure()); }

// Message
void    Cure::use(ICharacter& target) {
    std::cout << GREEN << "* heals " << target.getName() << "'s wounds *\n" << RESET;
}
