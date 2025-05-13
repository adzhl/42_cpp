/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:46:19 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/13 08:22:25 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include <ctime>
#include <cstdlib>

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"

#define MAX_VAL 750

int main()
{
    // Creating Array<int> numbers of size MAX_VAL
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));

    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    std::cout << YELLOW << "=== Testing copy constructor and copy assignment operator ===\n" << RESET;
    Array<int> tmp = numbers;
    Array<int> test(tmp);

    std::cout << "Value of numbers[0] before: " << numbers[0] << '\n';
    std::cout << "Value of numbers[1] before: " << numbers[1] << "\n\n";

    std::cout << "Value of tmp[0] before: " << tmp[0] << '\n';
    std::cout << "Value of tmp[1] before: " << tmp[1] << "\n\n";

    std::cout << "Value of test[0] before: " << test[0] << '\n';
    std::cout << "Value of test[1] before: " << test[1] << "\n\n";


    // Modify tmp and see if numbers is unaffected
    tmp[0] = 12345;
    tmp[1] = 67890;

    std::cout << YELLOW << "After modifying tmp[0] and tmp[1]:\n" << RESET;
    std::cout << "numbers[0] after: " << numbers[0] << '\n';
    std::cout << "tmp[0] after: " << tmp[0] << "\n";
    std::cout << "test[0] after: " << test[0] << "\n\n";

    std::cout << "numbers[1] after: " << numbers[1] << '\n';
    std::cout << "tmp[1] after: " << tmp[1] << "\n";
    std::cout << "test[1] after: " << test[1] << "\n\n";

    test[0] = 55555;
    test[1] = 66666;
    std::cout << YELLOW << "After modifying test[0] and test[1]:\n" << RESET;
    std::cout << "numbers[0] after: " << numbers[0] << '\n';
    std::cout << "tmp[0] after: " << tmp[0] << '\n';
    std::cout << "test[0] after: " << test[0] << "\n\n";

    std::cout << "numbers[1] after: " << numbers[1] << '\n';
    std::cout << "tmp[1] after: " << tmp[1] << '\n';
    std::cout << "test[1] after: " << test[1] << "\n\n";

    // Verifying all values match mirror
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "Mismatch at index " << i << '\n';
            return (1);
        }
    }

    std::cout << YELLOW << "Testing out-of-bounds access (negative index)\n" << RESET;
    try { numbers[-1] = 0; }
    catch(const std::exception& e) { std::cerr << RED << e.what() << '\n' << RESET; }

    std::cout << YELLOW << "Testing out-of-bounds access (index == size)\n" << RESET;
    try { numbers[MAX_VAL] = 0; }
    catch(const std::exception& e) { std::cerr << RED << e.what() << "\n\n" << RESET; }

    std::cout << YELLOW << "Filling array again with new random values\n" << RESET;
    std::cout << "numbers[0] before refill: " << numbers[0] << '\n';
    for (int i = 0; i < MAX_VAL; i++)
        numbers[i] = rand();

    std::cout << "numbers[0] after refill: " << numbers[0] << '\n';

    delete[] mirror;

    std::cout << YELLOW << "\n=== Testing with std::string ===\n" << RESET;
    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = "World";
    stringArray[2] = "!";
    for (unsigned int i = 0; i < stringArray.size(); ++i)
        std::cout << stringArray[i] << ' ';
    std::cout << '\n';

    // Testing copy and assignment
    Array<std::string> copyArray = stringArray;
    copyArray[1] = "42";
    std::cout << "Original: " << stringArray[1] << '\n';
    std::cout << "Copy: " << copyArray[1] << '\n';

    return (0);
}
