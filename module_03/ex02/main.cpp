/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:24:06 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/14 12:13:15 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    std::cout << YELLOW << "\n=== Creating FragTrap ===" << std::endl << RESET;
    FragTrap frag("Claude");

    std::cout << YELLOW << "\n=== Initial Stats ===" << std::endl << RESET;
    frag.printStats();

    std::cout << YELLOW << "\n=== FragTrap Actions ===" << std::endl << RESET;
    frag.attack("target_dummy");
    frag.takeDamage(20);
    frag.beRepaired(10);
    frag.highFivesGuys();

    // std::cout << YELLOW << "\n=== Copy and Assignment ===" << std::endl << RESET;
    // FragTrap clone(frag);
    // FragTrap assigned;
    // assigned = frag;
    // clone.printStats();
    // assigned.printStats();

    std::cout << YELLOW << "\n=== End of Program ===" << std::endl << RESET;
    return (0);
}