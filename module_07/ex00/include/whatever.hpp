/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:58:45 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/09 10:15:03 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

// what is a template?
// - allows you to write generic & usable code.
// - works with any type (no need to create separate functions for each type)
// - avoids code duplication

// types of templates
// 1. Function Templates - generic function that works with any data type - to reuse logic
// 2. Class Templates - defines a generic class 
//                    - to create data structures/utility classes that works with any type 

template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
const T& min(const T& a, const T& b) {
    return ((a < b) ? a : b);
}

template <typename T>
const T& max(const T& a, const T& b) {
    return ((a > b) ? a : b);
}

#endif