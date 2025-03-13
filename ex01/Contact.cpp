/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:09:53 by abinti-a          #+#    #+#             */
/*   Updated: 2025/03/13 13:41:46 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void Contact::setContact()
{
    std::cout << "Enter First Name: ";
    std::getline(std::cin, _firstName);

    std::cout << "Enter Last Name: ";
    std::getline(std::cin, _lastName);

    std::cout << "Enter Nickname: ";
    std::getline(std::cin, _nickname);

    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, _phoneNumber);
    
    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, _darkestSecret);

    if (_firstName.empty() || _lastName.empty() || _nickname.empty() || 
        _phoneNumber.empty() || _darkestSecret.empty())
    {
        system("clear");
        std::cout << "Error: All fields must be filled. Try again!\n";
        setContact();
    }
}

void Contact::getContact() const
{
    std::cout << "First Name: " << _firstName << '\n';
    std::cout << "Last Name: " << _lastName << '\n';
    std::cout << "Nickname: " << _nickname << '\n';
    std::cout << "Phone Number: " << _phoneNumber << '\n';
    std::cout << "Darkest Secret: " << _darkestSecret << '\n';
}

std::string formatField(const std::string &field)
{
    if (field.length() > 10)
        return (field.substr(0,9) + ".");
    return (field);
}

void Contact::displaySummary(int index) const
{
    std::cout << std::setw(10) << "Index" << "|"
                << std::setw(10) << "First Name" << "|"
                << std::setw(10) << "Last Name" << "|"
                << std::setw(10) << "Nickname" << "\n";

    std::cout << "---------------------------------------------\n";

    std::cout << std::setw(10) << index << "|"
                << std::setw(10) << formatField(_firstName) << "|"
                << std::setw(10) << formatField(_lastName) << "|"
                << std::setw(10) << formatField(_nickname) << '\n';
}
