/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:46:49 by abinti-a          #+#    #+#             */
/*   Updated: 2025/03/20 16:36:27 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *heapZombie = newZombie("heapZombie");
    heapZombie->announce();

    randomChump("stackZombie");
    delete heapZombie;

    return (0);
}
