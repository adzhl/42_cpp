/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:16:05 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/29 09:26:41 by abinti-a         ###   ########.fr       */
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

// std::vector<int>::iterator == typename T::iterator it
template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);

    if (it == container.end()) throw NotFoundException();

    return (it);
}

#endif

// STL (Standard Template Library) includes:
// Containers - ready-made data structures that stores elements
// Iterators - to transverse through containers (like a pointer/cursor)
// Algorithm - functions that operate on containers via iterators

// STL style - algorithm work on iterators, not on containers directly

// easyfind template 
// takes in any STL container of integers
// uses STL algorithm (std::find) to look for the value
// returns an iterator (pointer) to the found element 

// Sequence containers
// std::vector (Dynamic array) - [1, 2, 3, 4]
// std::deque (Double-ended queue) - [1, 2, 3] (push front/ back)
// std::list (Doubly linked list) - 1 <-> 2 <-> 3

// Associative containers (sorted by keys)
// std::map (Key-value pairs) - find elements by key (fast lookup)
// std::set (Unique sorted elements) - sorted elements
