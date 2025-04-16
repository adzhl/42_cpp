/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:34:02 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/16 08:44:20 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), _name("Default") {
    this->_hitPoints = FragTrap::DEFAULT_HP;
    this->_energyPoints = ScavTrap::DEFAULT_EP;
    this->_attackDamage = FragTrap::DEFAULT_AD;
    std::cout << "DiamondTrap Default is created\n";
}

// Custom constructor
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
    this->_hitPoints = FragTrap::DEFAULT_HP;
    this->_energyPoints = ScavTrap::DEFAULT_EP;
    this->_attackDamage = FragTrap::DEFAULT_AD;
    std::cout << "DiamondTrap " << this->_name <<  " is ready to die for the cause\n";
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other) { 
    std::cout << "DiamondTrap copy constructor called\n";
    *this = other; 
}

// Copy assignment operator
DiamondTrap&   DiamondTrap::operator=(const DiamondTrap& other) {
    std::cout << "DiamondTrap copy assignment operator called\n";
    if (this != &other) {
        ClapTrap::operator=(other);
        this->_name = other._name;
    }
    return (*this);
}

// Destructor
DiamondTrap::~DiamondTrap() { std::cout << "DiamondTrap " << this->_name << " has been defeated. Rest in Peace...\n"; }

void    DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI() {
    std::cout << BLUE << "DiamondTrap name: " << this->_name << '\n';
    std::cout << "ClapTrap name: " << ClapTrap::_name << '\n' << RESET;
}
