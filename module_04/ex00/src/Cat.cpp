/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 07:38:40 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/18 09:43:40 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructor
Cat::Cat() : Animal() {
    _type = "Cat";
    std::cout << "A cat has appeared!\n"; 
}

// Copy constructor
Cat::Cat(const Cat& other) : Animal(other) { std::cout << "Cat copy constructor called\n"; }

// Copy assignment operator
Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat copy assignment operator called\n";
    if (this != &other) { this->_type = other._type; }
    return (*this);
}

// Destructor
Cat::~Cat() { std::cout << "Cat ran away...\n"; }

void    Cat::makeSound() const { std::cout << "Meow\n"; }