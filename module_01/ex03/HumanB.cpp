/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:25:29 by abinti-a          #+#    #+#             */
/*   Updated: 2025/03/25 09:11:16 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

// & (reference) : ensure null is not passed
//               : avoid unnecessary copying
void    HumanB::setWeapon(Weapon& weapon) {
    this->_weapon = &weapon;
}

void    HumanB::attack() const {
    if (_weapon)
        std::cout << _name << " attacks with their " << _weapon->getType() << '\n';
    else
        std::cout << _name << " has no weapon to attack with!\n";
}
