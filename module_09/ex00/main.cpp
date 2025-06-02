/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:01:39 by abinti-a          #+#    #+#             */
/*   Updated: 2025/06/02 12:37:40 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) { std::cerr << "Error: must input one file!\n"; return (1); }

    std::ifstream data("data.csv");
    if (!data) { std::cerr << "Error: Cannot open file!\n"; return (1); }


    std::string header;
    std::getline(data, header);
    if (header != "date,exchange_rate") { std::cerr << "Error: Wrong header!\n"; return (1); }

    std::string line;
    while (std::getline(data, line)) {

    }
    return (0);
}