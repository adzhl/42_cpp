/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 07:38:40 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/18 13:13:29 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructor
Cat::Cat() : Animal() {
    _type = "Cat";
    _brain = new Brain();
    std::cout << "A cat has appeared!\n"; 
}

// Copy constructor
Cat::Cat(const Cat& other) : Animal(other) { 
    _brain = new Brain(*other._brain);
    std::cout << "Cat copy constructor called\n"; 
}

// Copy assignment operator
Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat copy assignment operator called\n";
    if (this != &other) {
        this->_type = other._type;
        delete _brain;
        _brain = new Brain(*other._brain); 
    }
    return (*this);
}

// Destructor
Cat::~Cat() { delete _brain; std::cout << "Cat ran away...\n"; }

// Make sound function
void    Cat::makeSound() const { std::cout << "Meow\n"; }

// Setter
void    Cat::setIdea(int index, const std::string& idea) { _brain->setIdea(index, idea); }

// Getter
std::string  Cat::getIdea(int index) const { return (_brain->getIdea(index)); }
