/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:27:55 by abinti-a          #+#    #+#             */
/*   Updated: 2025/06/06 09:58:46 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) { std::cerr << RED << "Error: must give one input!\n" << RESET; return (1); }

    RPN rpn;
    try {
        int result = rpn.evaluate(argv[1]);
        std::cout << result << '\n';
    } catch (std::exception& e) {
        std::cerr << RED << e.what() << '\n' << RESET;
        return (1);
    }

    return (0);
}
