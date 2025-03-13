/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:03:23 by abinti-a          #+#    #+#             */
/*   Updated: 2025/03/13 14:12:26 by abinti-a         ###   ########.fr       */
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
    _index = (_index % 8) + 1;
}

void PhoneBook::displayContacts() const
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
    {
        _array[i].displaySummary(i + 1);
        std::cout << "Value i after: " << i << "\n";
        std::cout << "contact count after: " << _contactCount << "\n";
    }
}