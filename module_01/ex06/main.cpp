/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:11:44 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/03 10:43:58 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {
    if (argc != 2) { std::cerr << "Usage: ./harlFilter <level>\n"; return (1); }

    Harl    myHarl;
    myHarl.complainFilter(argv[1]);

    return (0);
}
