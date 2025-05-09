/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:19:02 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/09 11:03:11 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void    iter(T* array, int length, void (*func)(T&)) {
    for (int i = 0; i < length; ++i)
        func(array[i]);
}

template <typename T>
void    printElement(T& elem) { std::cout << elem << '\n'; }

template <typename T>
void    incrementElement(T& elem) { ++elem; }

#endif