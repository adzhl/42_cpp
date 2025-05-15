/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:17:38 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/15 13:56:08 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <deque>

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define YELLOW  "\033[33m"

int main() {
    try {
        std::cout << YELLOW << "=== Testing with std::vector ===" << '\n' << RESET;
        std::vector<int> vec;
        for (int i = 0; i < 5; ++i)
            vec.push_back(i * 10);

        std::vector<int>::iterator itVec = easyfind(vec, 20);
        std::cout << "Found in vector: " << *itVec << '\n';

        // Test not found
        easyfind(vec, 100);

    } catch (const std::exception& e) {
        std::cout << RED << "Exception: " << e.what() << '\n' << RESET;
    }

    try {
        std::cout << YELLOW << "\n=== Testing with std::list ===" << '\n' << RESET;
        std::list<int> lst;
        for (int i = 0; i < 5; ++i)
            lst.push_back(i * 15);

        std::list<int>::iterator itList = easyfind(lst, 30);
        std::cout << "Found in list: " << *itList << '\n';

        // Test not found
        easyfind(lst, 1000);

    } catch (const std::exception& e) {
        std::cout << RED << "Exception: " << e.what() << '\n' << RESET;
    }

        try {
        std::cout << YELLOW << "\n=== Testing with std::deque ===" << '\n' << RESET;
        std::deque<int> deque;
        for (int i = 0; i < 5; ++i)
            deque.push_back(i * 20);

        std::deque<int>::iterator itDeq = easyfind(deque, 40);
        std::cout << "Found in deque: " << *itDeq << '\n';

        // Test not found
        easyfind(deque, 1000);

    } catch (const std::exception& e) {
        std::cout << RED << "Exception: " << e.what() << '\n' << RESET;
    }

    try {
        std::cout << YELLOW << "\n=== Testing with const container ===" << '\n' << RESET;
        const int arr[] = { 10, 20, 30 };
        const std::vector<int> constVec(arr, arr + 3);

        std::vector<int>::const_iterator itVec = easyfind(constVec, 20);
        std::cout << "Found in const vector: " << *itVec << '\n';

        easyfind(constVec, 40);

    } catch (const std::exception& e) {
        std::cout << RED << "Exception: " << e.what() << '\n' << RESET;
    }

    return (0);
}
