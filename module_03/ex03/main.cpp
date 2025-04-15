/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:42:52 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/14 15:49:28 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
    std::cout << YELLOW << "\n=== Constructing DiamondTrap ===\n" << RESET;
    DiamondTrap dt1("Shiny");

    std::cout << YELLOW << "\n=== Initial Stats ===" << std::endl << RESET;
    dt1.printStats();

    std::cout << YELLOW << "\n=== Testing attack (ScavTrap's attack) ===\n" << RESET;
    dt1.attack("target dummy");

    std::cout << YELLOW << "\n=== Testing takeDamage and beRepaired (ClapTrap's functions) ===\n" << RESET;
    dt1.takeDamage(30);
    dt1.beRepaired(20);

    std::cout << YELLOW << "\n=== Testing whoAmI (DiamondTrap special) ===\n" << RESET;
    dt1.whoAmI();

    std::cout << YELLOW << "\n=== Copy constructor test ===\n" << RESET;
    DiamondTrap dt2(dt1);
    dt2.whoAmI();

    std::cout << YELLOW << "\n=== Copy assignment test ===\n" << RESET;
    DiamondTrap dt3;
    dt3 = dt1;
    dt3.whoAmI();

    std::cout << YELLOW << "\n=== Deconstruction check ===\n" << RESET;
    // All destructors will be called at end of main

    return 0;
}
