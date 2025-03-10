/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:52:21 by abinti-a          #+#    #+#             */
/*   Updated: 2025/03/10 12:26:40 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void capitalize(int i, int argc, char *arg)
{
    if (!*arg)
        return;
    for (; *arg; arg++)
        std::cout << (char) std::toupper(* arg);
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
            capitalize(i, argc, argv[i]);
        std::cout << std::endl;
    }
    return (0);
}