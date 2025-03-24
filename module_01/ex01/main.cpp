/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:48:28 by abinti-a          #+#    #+#             */
/*   Updated: 2025/03/24 09:29:12 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    int N = 5;

    Zombie *horde = zombieHorde(N, "hordeZombie");
    if (horde) {
        std::cout << "Returned pointer: " << horde << '\n';
        std::cout << "Pointer of first zombie: " << &horde[0] << '\n';

        if (horde == &horde[0])
            std::cout << "zombieHorde() correctly returns a pointer to the first zombie!\n";
        else
            std::cout << "Pointer mismatch!\n";
    
        delete[] horde;
    }
    return (0);
}
