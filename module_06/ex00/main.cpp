/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:50:21 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/08 08:45:24 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    if (argc == 2) {
        std::string literal(argv[1]);
        ScalarConverter::convert(literal);
    }
    else { std::cout << "Error: invalid number of arguments!\n"; return (1); }

    return (0);
}