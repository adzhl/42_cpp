/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:49:45 by abinti-a          #+#    #+#             */
/*   Updated: 2025/03/24 09:28:16 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
    std::cout << "An unnamed zombie is created\n";
}

Zombie::~Zombie() {
    std::cout << _name << ": is destroyed\n";
}

void    Zombie::announce() {
    std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

void    Zombie::setName(std::string name) {
    _name = name;
}