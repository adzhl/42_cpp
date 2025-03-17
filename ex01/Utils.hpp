/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:08:51 by abinti-a          #+#    #+#             */
/*   Updated: 2025/03/17 10:13:20 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <string>
# include <cstdlib>

bool        whiteSpace(std::string input);
bool        isValid(std::string input, int flag);
bool        checkInput(const std::string &first, const std::string &last, const std::string &nickname, const std::string &phone, const std::string &secret);
std::string formatField(const std::string &field);

#endif