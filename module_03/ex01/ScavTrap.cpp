/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:10:13 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/16 09:09:43 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap() {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap Default is created\n";
}

// Constructor that takes in a name string
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " is created\n";
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) { std::cout << "ScavTrap copy constructor called\n"; *this = other; }

// Copy assignment operator
ScavTrap&   ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap copy assignment operator called\n";
    if (this != &other) 
        ClapTrap::operator=(other);

    return (*this);
}

// Destructor
ScavTrap::~ScavTrap() { std::cout << "ScavTrap " << _name << " is destroyed\n"; }

// Custom attack function for ScavTrap
void    ScavTrap::attack(const std::string& target) {
    if (this->_energyPoints > 0 && this->_hitPoints > 0) {
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!\n";
        this->_energyPoints--;
    }
    else if (this->_hitPoints <= 0)
        std::cout << RED << "ScavTrap " << this->_name << " is DEAD!\n" << RESET;
    else
        std::cout << "ScavTrap " << this->_name << " has no energy points to attack!\n";
    this->printStats();
}

void    ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode.\n";
}
