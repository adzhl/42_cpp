/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 07:27:46 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/18 07:59:10 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructor
Animal::Animal() : _type("Unidentified") { std::cout << "An animal is created. What animal could it be?\n"; }

// Copy constructor
Animal::Animal(const Animal& other) : _type(other._type) { std::cout << "Animal copy constructor called\n"; }

// Copy assignment operator
Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal copy assignment operator called\n";
    if (this != &other) { this->_type = other._type; }
    return (*this);
}

// Destructor
Animal::~Animal() { std::cout << "An unidentified animal has disappeared...\n"; }

// Getter
const   std::string&    Animal::getType() const { return (_type); }

void    Animal::makeSound() const { std::cout << "Unidentified sound\n"; }