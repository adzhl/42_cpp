/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:29:35 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/11 11:22:35 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap() : 
    _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Default is created\n";
}

// Constructor that takes in a name string
ClapTrap::ClapTrap(std::string name) :
    _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << _name << " is created\n";
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "Copy constructor called\n";
    *this = other;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "Copy assignment operator called\n";
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap() { std::cout << _name << " is destroyed\n"; }

void    ClapTrap::attack(const std::string& target) {
    
}