/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:29:17 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/14 11:40:36 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <sstream>

int main() {
    std::cout << YELLOW << "=== Creating ClapTrap ===" << std::endl << RESET;
    ClapTrap bot("Dimitri");

    std::cout << YELLOW << "\n=== Initial Stats ===" << std::endl << RESET;
    bot.printStats();

    std::cout << YELLOW << "\n=== Normal attack ===" << std::endl << RESET;
    bot.attack("target_dummy");

    std::cout << YELLOW << "\n=== Take damage ===" << std::endl << RESET;
    bot.takeDamage(3);

    std::cout << YELLOW << "\n=== Repair ===" << std::endl << RESET;
    bot.beRepaired(5);

    std::cout << YELLOW << "\n=== Drain energy by attacking ===" << std::endl << RESET;
    for (int i = 0; i < 8; ++i) {
        std::stringstream ss;
        ss << "target_" << i;
        bot.attack(ss.str());
    }

    std::cout << YELLOW << "\n=== Try attacking with 0 energy ===" << std::endl << RESET;
    bot.attack("final_target");

    std::cout << YELLOW << "\n=== Try repairing with 0 energy ===" << std::endl << RESET;
    bot.beRepaired(10);

    std::cout << YELLOW << "\n=== Take fatal damage ===" << std::endl << RESET;
    bot.takeDamage(999);  // HP goes to 0

    std::cout << YELLOW << "\n=== Try repairing when dead ===" << std::endl << RESET;
    bot.beRepaired(5);

    std::cout << YELLOW << "\n=== Try attacking when dead ===" << std::endl << RESET;
    bot.attack("ghost_target");

    std::cout << "\n=== Program ends ===" << std::endl;
    return 0;
}
