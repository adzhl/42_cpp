/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:08:35 by abinti-a          #+#    #+#             */
/*   Updated: 2025/03/17 10:31:50 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

bool    checkInput(const std::string &first, const std::string &last, const std::string &nickname, const std::string &phone, const std::string &secret)
{
    if (whiteSpace(first) || whiteSpace(last) || whiteSpace(nickname) || 
        whiteSpace(phone) || whiteSpace(secret))
    {
        system("clear");
        std::cout << "Error: All fields must be filled. Try again!\n";
        return (false);
    }

    if (!isValid(first, NAME) || !isValid(last, NAME))
    {
        system("clear");
        std::cout << "Error: Name must be alphabetical. Try again!\n";
        return (false);
    }

    if (!isValid(phone, PHONE))
    {
        system("clear");
        std::cout << "Error: Phone number must be numerical. Try again!\n";
        return (false);
    }
    
    return (true);
}

bool    whiteSpace(std::string input)
{
    for (size_t i = 0; i < input.length(); i++)
    {
        if (!std::isspace(input[i]))
            return (false);
    }
    return (true);
}

bool    isValid(std::string input, InputType type)
{
    for (size_t i = 0; i < input.length(); i++)
    {
        if (type == NAME && !std::isalpha(input[i]))
            return (false);
        else if (type == PHONE && !std::isdigit(input[i]))
            return (false);
    }
    return (true);
}

std::string formatField(const std::string &field)
{
    if (field.length() > 10)
        return (field.substr(0, 9) + ".");
    return (field);
}
