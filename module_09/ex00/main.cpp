/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:01:39 by abinti-a          #+#    #+#             */
/*   Updated: 2025/06/11 10:22:18 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    (void)argv;
    if (argc != 2) { std::cerr << "Error: must input one file!\n"; return (1); }

    BitcoinExchange btc;
    if (!btc.loadDatabase("data.csv")) return (1);
    btc.processInput(argv[1]);
    return (0);
}
