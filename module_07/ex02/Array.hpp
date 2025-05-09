/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:38:21 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/09 13:19:56 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

// class template
template <typename T>
class Array {
    private:
        unsigned int    _size;
        T*              _array;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array&          operator=(const Array& other);
        ~Array();

        T&              operator[](unsigned int index);
        const T&        operator[](unsigned int index) const;

        unsigned int    size() const;
} ;

#include "Array.tpp"

#endif