/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:47:08 by abinti-a          #+#    #+#             */
/*   Updated: 2025/03/20 14:46:33 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Initialization list
Zombie::Zombie(std::string name): _name(name) {}

// Constructor
Zombie::~Zombie()
{
    std::cout << _name << " is destroyed\n";
}

// Destructor
void Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}