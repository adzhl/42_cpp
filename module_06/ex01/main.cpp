/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:22:25 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/08 12:44:33 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    Data original;

    original.data = 42;

    uintptr_t raw = Serializer::serialize(&original);

    std::cout << "Original address: " << &original << '\n';
    std::cout << "Original data: " << original.data << '\n';

    Data* recovered = Serializer::deserialize(raw);

    std::cout << "Recovered address: " << recovered << '\n';
    std::cout << "Recovered id: " << recovered->data << '\n';
}

// Conversion between incompatible types

// Pointer and integer conversion
// Unrelated pointers
// Pointers are just memory addresses
// uintptr_t (unsigned integer) guaranteed to be able to hold a pointer

// serialization involves storing data as bytes & retrieves it
