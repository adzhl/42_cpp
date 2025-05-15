/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:16:05 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/15 13:46:51 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>

class NotFoundException : public std::exception {
    public:
        const char* what() const throw() { return ("Value not found in the container"); }
} ;

template <typename T>
typename T::const_iterator easyfind(const T& container, int value) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);

    if (it == container.end()) throw NotFoundException();

    return (it);
}

template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);

    if (it == container.end()) throw NotFoundException();

    return (it);
}

#endif

// Vectors - ready-made data structures that stores elements

// easyfind template 
// takes in any STL (standard template library) container of integers
// uses STL algorithm (std::find) to look for the value
// returns an iterator (pointer) to the found element 
// STL style - algorithm work on iterators, not on containers directly

// std::vector (Dynamic array) - by index
// std::deque (Double-ended queue) - push/pop front and back - access
// std::list (Doubly linked list) - find


// std::map (Key-value pairs) - find elements by key (fast lookup)
// std::set (Unique sorted elements) - sorted elements
