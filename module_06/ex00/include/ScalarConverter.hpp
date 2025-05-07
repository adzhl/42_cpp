/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 08:14:35 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/07 13:08:17 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

class ScalarConverter {
    public:
        static void convert(std::string literal);

    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter&    operator=(const ScalarConverter& other);
        ~ScalarConverter();
} ;

enum LiteralType {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO_FLOAT,
    PSEUDO_DOUBLE,
    INVALID
} ;

#endif

// Setting constructors as private prevents instantiation

// 1. Receive a string literal
// 2. Detect its type (char, int, float, double)
// 3. Convert to all other scalar types
// 4. Print the result in each type

// Types of casts
// 1. STATIC CAST
//  - standard type conversions
//  - converting between numeric types (int, float, double)
//  - upcasting in inheritance (Derived* to Base*)
//
// 2. DYNAMIC CAST
//  - safe downcasting in inheritance (Base* to Derived*)
//  - works with pointers/references to polymorphic classes
//  - failed downcasting -  pointer:   returns (nullptr)
//                       -  reference: throws std::bad_cast
//
// 3. CONST CAST
//  - add or remove const/volatile qualifiers from a variable (const int* to int*)
//  - if the original object was const, removing const and modifying the object is undefined behaviour
//
// 4. REINTERPRET_CAST
//  - bit-level (low level) reinterpretation
//  - allow casting between unrelated pointer types
//  - can lead to undefined behaviour
