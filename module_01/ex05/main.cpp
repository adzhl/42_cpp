/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:32:22 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/03 09:46:26 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
    Harl        myHarl;
    std::string level;

    std::cout   <<  "Enter a complaint level: (DEBUG, INFO, WARNING, ERROR) or type EXIT to quit\n";

    while (true) {
        std::getline(std::cin, level);
        if (std::cin.eof() || level == "EXIT")
            break;
        myHarl.complain(level);
    }
    return (0);
}
