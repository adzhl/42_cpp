/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:47:01 by abinti-a          #+#    #+#             */
/*   Updated: 2025/03/20 16:32:53 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Allocates memory on the heap using new
// Returns a pointer
// Memory must be deleted manually
Zombie *newZombie(std::string name)
{
    return new Zombie(name);
}
