/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:25:29 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/03 12:11:22 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

// & (reference) : always points to an object and cannot be NULL
//               : can't reassign it to point to a different object after initialization
// * (pointer)   : stores the address of the object it points to
//               : can be changed to point to a different object or set to NULL
// this is a pointer to the calling object/current instance of the class
// this->_weapon is the same as (*this)._weapon
// this is used here due to similar variable names
void    HumanB::setWeapon(Weapon* weapon) {
    this->_weapon = weapon;
}

void    HumanB::attack() const {
    if (_weapon)
        std::cout << _name << " attacks with their " << _weapon->getType() << '\n';
    else
        std::cout << _name << " has no weapon to attack with!\n";
}
