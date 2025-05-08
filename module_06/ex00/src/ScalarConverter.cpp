/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:21:36 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/08 10:34:16 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Constructor
ScalarConverter::ScalarConverter() {}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

// Copy assignment operator
ScalarConverter&    ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return (*this); }

// Destructor
ScalarConverter::~ScalarConverter() {}


// Set Type
// find('.') != npos(not found) : if '.' is found in string
int  ScalarConverter::setType(std::string& literal) {
    if (literal.empty()) { return (INVALID); }

    if (isPseudoFloat(literal)) { return (FLOAT); }

    if (isPseudoDouble(literal)) { return (DOUBLE); }

    if (isChar(literal)) { return (CHAR); }

    if (isFloat(literal)) { return (FLOAT); }

    if (checkNum(literal)) { return (literal.find('.') != std::string::npos ? DOUBLE : INT); }

    return (INVALID);
}

// Convert function
void    ScalarConverter::convert(std::string literal) {
    int type = setType(literal);

    switch (type) {
        case (CHAR): {
            char c = literal[0];
            print(c, static_cast<long>(c), static_cast<float>(c), static_cast<double>(c));
            break;
        }

        case (INT): {
            long i = std::atol(literal.c_str());
            print(static_cast<char>(i), i, static_cast<float>(i), static_cast<double>(i));
            break;
        }

        case (FLOAT): {
            float f = std::strtof(literal.c_str(), 0);
            print(static_cast<char>(f), static_cast<long>(f), f, static_cast<double>(f));
            break;
        }

        case (DOUBLE): {
            double d = std::strtod(literal.c_str(), 0);
            print(static_cast<char>(d), static_cast<long>(d), static_cast<float>(d), d);
            break;
        }

        case (INVALID):
            std::cout << "Error: invalid literal\n";
    }
}