/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:10:58 by abinti-a          #+#    #+#             */
/*   Updated: 2025/06/04 09:41:00 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib> 
#include <ctime>    

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define YELLOW  "\033[33m"

template <typename T>
void    printContainer(T& container) {
    std::cout << "{ ";
    for (typename T::iterator i = container.begin(); i != container.end(); ++i) {
        std::cout << *i;

        if (i + 1 != container.end())
            std::cout << ", ";
    }
    std::cout << " }\n";
}

void constructorTest() {
    std::cout << YELLOW << "=== CONSTRUCTOR TEST ===" << RESET << '\n';
    std::cout << YELLOW << "Default Constructor:" << RESET << '\n';
    Span def;
    std::cout << "Default constructor size: " << def.size() << '\n';

    std::cout << YELLOW << "\nCopy Constructor:" << RESET << '\n';
    Span ori(3);
    ori.addNumber(1);
    ori.addNumber(2);
    ori.addNumber(3);
    Span copy(ori);
    Span another = copy;

    std::cout << "Size of copy: " << copy.size() << '\n';
    std::cout << "Data in copy: ";
    printContainer(copy.getNumbers());
    std::cout << "Size of another: " << another.size() << '\n';
    std::cout << "Data in another: ";
    printContainer(another.getNumbers());
}

int main() {
    constructorTest();

    std::cout << YELLOW << "\n=== BASIC TEST ===" << RESET << '\n';
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Data in Span: ";
        printContainer(sp.getNumbers());
        std::cout << "Shortest Span: " << sp.shortestSpan() << '\n';
        std::cout << "Longest Span: " << sp.longestSpan() << '\n';

        sp.addNumber(42);
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

        // std::cout << "Data in span: ";
        // printContainer(bigSpan.getNumbers());
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

        std::cout << "Data in span: ";
        printContainer(rangeSpan.getNumbers());
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

    try {
        std::cout << YELLOW << "\n=== NEGATIVE NUMBER TEST ===" << RESET << '\n';
        Span span(2);
        span.addNumber(2147483647);
        span.addNumber(-2147483648);

        std::cout << "Data in span: ";
        printContainer(span.getNumbers());
        std::cout << "Shortest Span: " << span.shortestSpan() << '\n';
        std::cout << "Longest Span: " << span.longestSpan() << '\n';
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << '\n';
    }

    return (0);
}