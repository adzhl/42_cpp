/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:52:21 by abinti-a          #+#    #+#             */
/*   Updated: 2025/03/19 12:33:33 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void capitalize(int i, int argc, std::string arg)
{
    if (arg.empty())
        return;
    for (size_t j = 0; j < arg.length(); j++)
        arg[j] = std::toupper(arg[j]);
    std::cout << arg;
    if (i < argc - 1)
        std::cout << " ";
}

int main(int argc, char **argv)
{
    if (argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; i < argc; i++)
            capitalize(i, argc, std::string (argv[i]));
        std::cout << std::endl;
    }
    return (0);
}