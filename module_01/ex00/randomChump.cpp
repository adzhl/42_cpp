/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:47:05 by abinti-a          #+#    #+#             */
/*   Updated: 2025/03/20 16:31:39 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Creates object on the stack
// Automatically destroyed when function ends
void randomChump(std::string name)
{
    Zombie myZombie(name);
    myZombie.announce();
}
