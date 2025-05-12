/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:11:24 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/12 11:06:51 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

// members are initialized in the order they appear in the class (header)
// not the order in the initializer list
// always match the intializer list order to declaration order

template <typename T>
Array<T>::Array() : _size(0), _array(NULL) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _array(new T[n]()) {}

template <typename T>
Array<T>::Array(const Array& other): _size(other._size), _array(new T[other._size]) {
    for (size_t i = 0; i < _size; ++i)
        _array[i] = other._array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] _array;

        _size = other._size;
        _array = new T[_size];
        for (size_t i = 0; i < _size; ++i)
            _array[i] = other._array[i];
    }
    return (*this);
}

template <typename T>
Array<T>::~Array() { delete[] _array; }

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size) { throw std::out_of_range("Index out of bounds"); }

    return _array[index];
}

template <typename T>
const T&    Array<T>::operator[](unsigned int index) const {
    if (index >= _size) { throw std::out_of_range("Index out of bounds"); }

    return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const { return (_size); }


#endif