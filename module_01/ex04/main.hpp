/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:54:03 by abinti-a          #+#    #+#             */
/*   Updated: 2025/03/27 13:10:43 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

#include <iostream>
#include <string>
#include <fstream>

void            replaceLine(std::string &line, const std::string &s1, const std::string &s2);
bool            checkS1(std::string s1);
std::ifstream   handleInput(char *argv);
std::ofstream   handleOutput(char *argv);

#endif