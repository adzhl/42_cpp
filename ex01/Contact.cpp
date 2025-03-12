/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:09:53 by abinti-a          #+#    #+#             */
/*   Updated: 2025/03/12 13:20:23 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setContact()
{
    std::cout << "Enter First Name: ";
    std::getline(std::cin, first_name);

    std::cout << "Enter Last Name: ";
    std::getline(std::cin, last_name);

    std::cout << "Enter Nickname: ";
    std::getline(std::cin, nickname);

    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, phone_number);
    
    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, darkest_secret);
}

void Contact::getContact()
{
    std::cout << "First Name: " << first_name << '\n';
    std::cout << "Last Name: " << last_name << '\n';
    std::cout << "Nickname: " << nickname << '\n';
    std::cout << "Phone Number: " << phone_number << '\n';
    std::cout << "Darkest Secret: " << darkest_secret << '\n';
}

int main()
{
    Contact myContact;
    std::string input;

    while (true)
    {
        std::cout << "Enter Command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, input);

        if (input == "ADD")
            myContact.setContact();
        else if (input == "SEARCH")
            myContact.getContact();
        else if (input == "EXIT")
            break;
        
        system("clear");
    }
    return (0);
}