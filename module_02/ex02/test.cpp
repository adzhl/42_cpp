/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 07:43:43 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/09 07:47:57 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main() {
    Fixed a(10);
    Fixed b(2);
    Fixed c(10);  

    std::cout << "\nCOMPARISON OPERATORS:\n";
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
    std::cout << "a == c: " << (a == c) << std::endl;
    std::cout << "a < b : " << (a < b) << std::endl;
    std::cout << "a <= c: " << (a <= c) << std::endl;
    std::cout << "a > b : " << (a > b) << std::endl;
    std::cout << "a >= c: " << (a >= c) << std::endl;

    std::cout << "\nARITHMETIC OPERATORS:\n";
    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "a - b = " << (a - b) << std::endl;
    std::cout << "a * b = " << (a * b) << std::endl;
    std::cout << "a / b = " << (a / b) << std::endl;

    return 0;
}
