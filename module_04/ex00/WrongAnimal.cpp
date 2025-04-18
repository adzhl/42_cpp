/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 08:12:59 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/18 08:14:15 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructor
WrongAnimal::WrongAnimal() : _type("Unidentified") { std::cout << "An WrongAnimal is created. What WrongAnimal could it be?\n"; }

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) { std::cout << "WrongAnimal copy constructor called\n"; }

// Copy assignment operator
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "WrongAnimal copy assignment operator called\n";
    if (this != &other) { this->_type = other._type; }
    return (*this);
}

// Destructor
WrongAnimal::~WrongAnimal() { std::cout << "An unidentified WrongAnimal has disappeared...\n"; }

// Getter
const   std::string&    WrongAnimal::getType() const { return (_type); }

void    WrongAnimal::makeSound() const { std::cout << "Unidentified sound\n"; }