/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:50:02 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/14 11:00:22 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    std::cout << YELLOW << "=== Creating ScavTrap ===" << std::endl << RESET;
    ScavTrap scav("Jack");

    std::cout << YELLOW << "\n=== Initial Stats ===" << std::endl << RESET;
    scav.printStats();
    
    std::cout << YELLOW << "\n=== ScavTrap Actions ===" << std::endl << RESET;
    scav.attack("target_dummy");
    scav.takeDamage(30);
    scav.beRepaired(20);
    scav.guardGate();

    std::cout << YELLOW << "\n=== End of Program ===" << std::endl << RESET;
    return 0;
}
