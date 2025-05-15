/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:17:38 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/15 11:18:28 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>

int main() {
    try {
        std::cout << "=== Testing with std::vector ===" << '\n';
        std::vector<int> vec;
        for (int i = 0; i < 5; ++i)
            vec.push_back(i * 10);

        std::vector<int>::iterator itVec = easyfind(vec, 20);
        std::cout << "Found in vector: " << *itVec << '\n';

        // Test not found
        easyfind(vec, 100);

    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << '\n';
    }

    try {
        std::cout << "\n=== Testing with std::list ===" << '\n';
        std::list<int> lst;
        for (int i = 0; i < 5; ++i)
            lst.push_back(i * 15);

        std::list<int>::iterator itList = easyfind(lst, 30);
        std::cout << "Found in list: " << *itList << '\n';

        // Test not found
        easyfind(lst, 1000);

    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << '\n';
    }

    try {
        std::cout << "\n=== Testing with const container ===" << '\n';
        const int arr[] = { 10, 20, 30 };
        const std::vector<int> constVec(arr, arr + 3);
        easyfind(constVec, 20);
        std::cout << "Found in const vector\n";
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << '\n';;
    }

    return (0);
}
