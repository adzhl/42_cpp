/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:32:30 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/03 09:50:20 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void    Harl::debug() {
    std::cout   << "\n[DEBUG]\n"
                << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n"; 
}

void    Harl::info() {
    std::cout   << "\n[INFO]\n"
                << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void    Harl::warning() {
    std::cout   << "\n[WARNING]\n" 
                << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n";
}        

void    Harl::error() {
    std::cout   << "\n[ERROR]\n" 
                << "This is unacceptable! I want to speak to the manager now.\n";
}

// Function pointer array stores pointers to corresponding functions
// Lookup table map strings to functions
void    Harl::complain(std::string level) {
    void (Harl::*functions[])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            (this->*functions[i])();
            return ;
        }
    }
    std::cout << "Error: Complaint not found!\n";
}
