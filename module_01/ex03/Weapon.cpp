/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:24:45 by abinti-a          #+#    #+#             */
/*   Updated: 2025/03/25 08:31:11 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {}

// const std::string& : returns unmodifiable string & prevents unnecessary copying
// ~ const {} : ensure function does not modify variables in the class
const std::string&    Weapon::getType() const {
    return (_type);
}

void    Weapon::setType(std::string newType) {
    _type = newType;
}
