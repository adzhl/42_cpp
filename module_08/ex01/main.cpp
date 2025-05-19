/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:10:58 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/19 11:46:27 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>  // rand, srand
#include <ctime>    // time

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define YELLOW  "\033[33m"

int main() {
    std::cout << YELLOW << "=== BASIC TEST ===" << RESET << '\n';
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << '\n';
        std::cout << "Longest Span: " << sp.longestSpan() << '\n';

        // Uncommenting this should throw an error
        // sp.addNumber(42);
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << '\n';
    }

    std::cout << "\n" << YELLOW << "=== EXCEPTION TEST ===" << RESET << '\n';
    try {
        Span sp(1);
        sp.addNumber(42);
        std::cout << "Trying shortestSpan on 1 element..." << '\n';
        std::cout << sp.shortestSpan() << '\n';
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << '\n';
    }

    std::cout << "\n" << YELLOW << "=== RANGE TEST (10,000 elements) ===" << RESET << '\n';
    try {
        Span bigSpan(10000);
        for (int i = 0; i < 10000; ++i)
            bigSpan.addNumber(rand());

        std::cout << "Shortest Span: " << bigSpan.shortestSpan() << '\n';
        std::cout << "Longest Span: " << bigSpan.longestSpan() << '\n';
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << '\n';
    }

    std::cout << "\n" << YELLOW << "=== ADD RANGE TEST ===" << RESET << '\n';
    try {
        Span rangeSpan(6);
        std::vector<int> nums;
        nums.push_back(10);
        nums.push_back(20);
        nums.push_back(30);
        rangeSpan.addRange(nums.begin(), nums.end());

        rangeSpan.addNumber(100);
        rangeSpan.addNumber(150);
        rangeSpan.addNumber(200);
        std::cout << "Shortest Span: " << rangeSpan.shortestSpan() << '\n';
        std::cout << "Longest Span: " << rangeSpan.longestSpan() << '\n';
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << '\n';
    }

    std::cout << "\n" << YELLOW << "=== RANGE OVERFLOW TEST ===" << RESET << '\n';
    try {
        Span overflow(3);
        std::vector<int> overflowData(4, 1); // 4 elements initialized to 1
        overflow.addRange(overflowData.begin(), overflowData.end());
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << '\n';
    }

    return (0);
}