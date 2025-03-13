/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:03:23 by abinti-a          #+#    #+#             */
/*   Updated: 2025/03/13 13:41:12 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    _index = 1;
    _contactCount = 1;
}

void PhoneBook::addContact()
{
    if (_contactCount < 9)
        _contactCount++;
    
    _array[_index].setContact();
    _index = (_index % 8) + 1;
}

void PhoneBook::displayContacts() const
{
    if (_contactCount == 1)
    {
        std::cout << "No Contacts available!\n";
        return;
    }
    
    for (int i = 1; i < _contactCount; i++)
        _array[i].displaySummary(i);
}