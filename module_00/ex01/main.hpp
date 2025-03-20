/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:16:56 by abinti-a          #+#    #+#             */
/*   Updated: 2025/03/13 10:23:33 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# include "PhoneBook.hpp"

void addCommand(PhoneBook &myPhoneBook);
void searchCommand(PhoneBook &myPhoneBook);
void exitCommand();
void wrongCommand();

#endif