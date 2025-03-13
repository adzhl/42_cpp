/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 08:34:26 by abinti-a          #+#    #+#             */
/*   Updated: 2025/03/13 10:27:28 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main()
{
    PhoneBook myPhoneBook;
    std::string input;

    system("clear");
    std::cout << "Welcome to my PhoneBook!\n";
    while (true)
    {
        std::cout << "Enter Command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, input);

        if (input == "ADD")
            addCommand(myPhoneBook);
        else if (input == "SEARCH")
            searchCommand(myPhoneBook);
        else if (input == "EXIT")
            exitCommand();
        else
            wrongCommand();
    }
    return (0);
}

void addCommand(PhoneBook &myPhoneBook)
{
    system("clear");
    myPhoneBook.addContact();
    system("clear");
    std::cout << "Contact Added Successfully!\n";
}

void searchCommand(PhoneBook &myPhoneBook)
{
    system("clear");
    myPhoneBook.displayContacts();
}

void exitCommand()
{
    system("clear");
    std::cout << "Goodbye!\n";
    exit(0);
}

void wrongCommand()
{
    system("clear");
    std::cout << "Invalid Command. Use ADD, SEARCH or EXIT only\n";
}
