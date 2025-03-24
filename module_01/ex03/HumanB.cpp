/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:25:29 by abinti-a          #+#    #+#             */
/*   Updated: 2025/03/24 11:09:26 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _type(NULL) {}

void    HumanB::setWeapon(Weapon& type) {
    _type = &type;
}

void    HumanB::attack() const {
    if (_type)
        std::cout << _name << " attacks with their " << _type->getType() << '\n';
    else
        std::cout << _name << " has no weapon to attack with!\n";
}

