/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 08:14:38 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/18 08:17:30 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Constructor
WrongCat::WrongCat() : WrongAnimal() {
    _type = "WrongCat";
    std::cout << "A WrongCat has appeared!\n"; 
}

// Copy constructor
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) { std::cout << "WrongCat copy constructor called\n"; }

// Copy assignment operator
WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "WrongCat copy assignment operator called\n";
    if (this != &other) { this->_type = other._type; }
    return (*this);
}

// Destructor
WrongCat::~WrongCat() { std::cout << "WrongCat ran away...\n"; }

void    WrongCat::makeSound() const { std::cout << "Meow?\n"; }