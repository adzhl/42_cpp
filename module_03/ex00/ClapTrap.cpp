/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:29:35 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/14 09:17:19 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap() : 
    _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap Default is created\n";
}

// Constructor that takes in a name string
ClapTrap::ClapTrap(std::string name) :
    _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap" << _name << " is created\n";
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) { *this = other; }

// Copy assignment operator
ClapTrap&   ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return (*this);
}

// Destructor
ClapTrap::~ClapTrap() { std::cout << "ClapTrap " << _name << " is destroyed\n"; }

// Stats printer for HP and EP
void    ClapTrap::printStats() {
    std::cout << GREEN << "\n[ CURRENT STATS FOR CLAPTRAP " << this->_name << " ]\n";
    std::cout << GREEN << "---> HP: " << this->_hitPoints << "\n";
    std::cout << GREEN << "---> EP: " << this->_energyPoints << "\n\n" << RESET;
}

// Attack   : costs 1 energy point
//          : cannot attack with 0 energy point or 0 hit points
void    ClapTrap::attack(const std::string& target) {
    if (this->_energyPoints > 0 && this->_hitPoints > 0) {
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!\n";
        this->_energyPoints--;
    }
    else if (this->_hitPoints <= 0)
        std::cout << RED << "ClapTrap " << this->_name << " is DEAD!\n" << RESET;
    else
        std::cout << "ClapTrap " << this->_name << " has no energy points to attack!\n";
    this->printStats();
}

// Take Damage  : reduces hit points by amount specified
void    ClapTrap::takeDamage(unsigned int amount) {
    this->_hitPoints -= amount;
    std::cout << "ClapTap " << this->_name << " takes " << amount << " damage!\n";

    if (this->_hitPoints <= 0) { 
        std::cout <<  RED << "ClapTrap " << this->_name << " can't fight anymore! He's DEAD!\n" << RESET;
    }
    this->printStats();
}

// Repair   : increase hit points by amount specified
//          : consumes 1 energy point
void    ClapTrap::beRepaired(unsigned int amount) {
    if (this->_energyPoints > 0 && this->_hitPoints > 0) {
        this->_hitPoints += amount;
        std::cout << "ClapTrap " << this->_name << " heals itself by " << amount << " HP\n";
        this->_energyPoints--;
    }
    else if (this->_hitPoints <= 0)
        std::cout << RED << "ClapTrap " << this->_name << " is DEAD! Can't do anything now...\n" << RESET;
    else
        std::cout << "ClapTrap " << this->_name << " has no energy points to heal itself!\n";
    this->printStats();
}
