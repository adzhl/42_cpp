/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 07:55:45 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/18 10:41:51 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructor
Dog::Dog() : Animal() {
    _type = "Dog";
    _brain = new Brain();
    std::cout << "A dog has appeared!\n"; 
}

// Copy constructor
Dog::Dog(const Dog& other) : Animal(other) { 
    _brain = new Brain(*other._brain);
    std::cout << "Dog copy constructor called\n"; 
}

// Copy assignment operator
Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog copy assignment operator called\n";
    if (this != &other) { 
        this->_type = other._type;
        delete _brain;
        _brain = new Brain(*other._brain); 
    }
    return (*this);
}

// Destructor
Dog::~Dog() { delete _brain; std::cout << "Dog ran away...\n"; }

void    Dog::makeSound() const { std::cout << "Woof\n"; }