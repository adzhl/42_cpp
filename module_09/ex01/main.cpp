/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:27:55 by abinti-a          #+#    #+#             */
/*   Updated: 2025/06/06 08:41:20 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) { std::cerr << RED << "Error: must give one input!\n" << RESET; return (1); }

    RPN rpn;
    try {
        int result = rpn.evaluate(argv[1]);
        std::cout << result << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return (0);
}