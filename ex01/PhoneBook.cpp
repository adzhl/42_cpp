/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:03:23 by abinti-a          #+#    #+#             */
/*   Updated: 2025/03/14 13:13:34 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    _index = 0;
    _contactCount = 0;
}

void PhoneBook::addContact()
{
    if (_contactCount < 8)
        _contactCount++;
    
    _array[_index].setContact();
    _index = (_index + 1 ) % 8;
}

void PhoneBook::promptIndex()
{
    std::string input;

    std::cout << "Enter contact index: ";
    std::getline(std::cin, input);

    if (input.length() == 1 && input[0] > '0' && input[0] < '9')
    {
        int input_value = input[0] - '0';
        if (input_value > _contactCount)
        {
            std::cout << "Error: Contact doesn't exist!\n";
            return;
        }
        system("clear");
        _array[input_value - 1].getContact();
    }
    else
        std::cout << "Error: Index doesn't exist. Enter numbers between 1 to 9 only\n";
}

void PhoneBook::displayContacts()
{
    if (_contactCount == 0)
    {
        std::cout << "No Contacts available!\n";
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
    << std::setw(10) << "First Name" << "|"
    << std::setw(10) << "Last Name" << "|"
    << std::setw(10) << "Nickname" << "\n";

    std::cout << "---------------------------------------------\n";
    
    for (int i = 0; i < _contactCount; i++)
        _array[i].displaySummary(i + 1);

    promptIndex();
}
