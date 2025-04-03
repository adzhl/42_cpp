/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:12:03 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/03 10:54:41 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void    Harl::debug() {
    std::cout   << "[DEBUG]\n"
                << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!\n\n"; 
}

void    Harl::info() {
    std::cout   << "[INFO]\n"
                << "I cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n\n";
}

void    Harl::warning() {
    std::cout   << "[WARNING]\n" 
                << "I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month.\n\n";
}        

void    Harl::error() {
    std::cout   << "[ERROR]\n" 
                << "This is unacceptable! I want to speak to the manager now.\n\n";
}

// switch only works with int or char (not string)
// when 'break' is not added in between cases -> fall-through behaviour (execute remaining cases)
void    Harl::complainFilter(std::string level) {

    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    int index = -1;
    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            index = i;
            break;
        }
    }

    switch(index) {
        case (0):
            debug();
        case (1):
            info();
        case (2):
            warning();
        case (3):
            error();
            break;
        default:
            std::cout << "[Probably complaining about insignificant problems]\n";
            break;
    }
}
