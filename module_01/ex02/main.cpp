/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:31:28 by abinti-a          #+#    #+#             */
/*   Updated: 2025/03/24 10:20:32 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

// string variable = "string"; creates string in memory
// *stringPTR; stores the address of variable
// &stringPTR; An alias of variable with the same memory
int main() {
    std::string brain = "HI THIS IS BRAIN";

    std::string *stringPTR = &brain;

    std::string &stringREF = brain;

    std::cout << "Memory address of brain: " << &brain << '\n';
    std::cout << "Memory address of stringPTR: " << stringPTR << '\n';
    std::cout << "Memory address of stringREF: " << &stringREF << '\n';

    std::cout << "\nValue of brain: " << brain << '\n';
    std::cout << "Value of stringPTR: " << *stringPTR << '\n';
    std::cout << "Value of stringREF: " << stringREF << '\n';

    return (0);
}