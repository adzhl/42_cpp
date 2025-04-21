/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 09:09:13 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/21 12:04:52 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Default constructor
Character::Character() : _name("Unnamed fella") {
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
    std::cout << "Character " << this->_name << " constructor called\n"; 
}

// Custom constructor
Character::Character(std::string name) : _name(name) {
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
    std::cout << "Character " << this->_name << " constructor called\n"; 
}

// Copy constructor
Character::Character(const Character& other) : _name(other._name) {
    for (int i = 0; i < 4; i++) {
        if (other._inventory[i] != NULL)
            this->_inventory[i] = other._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
    }
    std::cout << "Character copy constructor called\n";
}

// Copy assignment operator
Character&  Character::operator=(const Character& other) {
    std::cout << "Character copy assignment operator called\n";
    if (this != &other) {
        this->_name = other._name;
        for (int i = 0; i < 4; i++)
        {
            if (this->_inventory[i]) {
                delete this->_inventory[i];
                this->_inventory[i] = NULL;
            }
        }
        for (size_t i = 0; i < 4; i++)
        {
            if (other._inventory[i])
                this->_inventory[i] = other._inventory[i]->clone();
        }
    }
    return (*this);
}

// Destructor
Character::~Character() { 
    for (int i = 0; i < 4; i++)
        delete this->_inventory[i];
    std::cout << "Character destructor called\n"; 
}

// Getter
std::string const&  Character::getName() const { return (this->_name); }

// Equip
void    Character::equip(AMateria* m) {
    if (!m) { return; }

    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i] == NULL) {
            this->_inventory[i] = m;
            std::cout << YELLOW << m->getType() << " has been equipped to " << this->_name << " in slot " << i << '\n' << RESET ;
            return;
        }
    }
    
    std::cout << RED << m->getType() << " cannot be equipped. Inventory is full!\n" << RESET;
}

// Unequip
void    Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && this->_inventory[idx]) {
        this->_inventory[idx] = NULL;
        std::cout << YELLOW << "Item has been unequipped from " << this->_name << '\n' << RESET;
    }
}

// Use
void    Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && this->_inventory[idx])
        this->_inventory[idx]->use(target);
}
