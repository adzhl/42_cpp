/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:18:49 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/16 08:35:12 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Default constructor
FragTrap::FragTrap() : ClapTrap() {
    _hitPoints = DEFAULT_HP;
    _energyPoints = DEFAULT_EP;
    _attackDamage = DEFAULT_AD;
    std::cout << "FragTrap Default is created\n";
}

// Constructor that takes in a name string
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    _hitPoints = DEFAULT_HP;
    _energyPoints = DEFAULT_EP;
    _attackDamage = DEFAULT_AD;
    std::cout << "FragTrap " << _name << " is ready for battle\n";
}

// Copy constructor
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) { std::cout << "FragTrap copy constructor called\n"; *this = other; }

// Copy assignment operator
FragTrap&   FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap copy assignment operator called\n";
    if (this != &other) 
        ClapTrap::operator=(other);

    return (*this);
}

// Destructor
FragTrap::~FragTrap() { std::cout << "FragTrap " << _name << " has been defeated\n"; }

// Custom attack function for FragTrap
void    FragTrap::attack(const std::string& target) {
    if (this->_energyPoints > 0 && this->_hitPoints > 0) {
        std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!\n";
        this->_energyPoints--;
    }
    else if (this->_hitPoints <= 0)
        std::cout << RED << "FragTrap " << this->_name << " is DEAD!\n" << RESET;
    else
        std::cout << "FragTrap " << this->_name << " has no energy points to attack!\n";
    this->printStats();
}

void    FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << this->_name << " requests a high-five.\n";
}