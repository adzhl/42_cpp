/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:21:36 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/07 15:11:08 by abinti-a         ###   ########.fr       */
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


// Check type functions
bool    isChar(std::string& literal) {
    return (literal.length() == 1 && std::isalpha(literal[0]));
    //     return (true);
    // return (false);
}

bool    isPseudoFloat(std::string& literal) {
    return (literal == "nanf" || literal == "-inff" || literal == "+inff");
    //     return (true);
    // return (false);
}

bool    isPseudoDouble(std::string& literal) {
    return (literal == "nan" || literal == "-inf" || literal == "+inf" || literal == "inf");
    //     return (true);
    // return (false);
}

bool    checkNum(std::string& literal) {
    int i = 0;

    if (literal[i] == '+' || literal[i] == '-') { literal[i]++; }

    while
}

bool    isFloat(std::string& literal) {
    
}

int setType(std::string& literal) {
    if (literal.empty()) { return (INVALID); }

    if (isPseudoFloat(literal)) { return (PSEUDO_FLOAT); }

    if (isPseudoDouble(literal)) { return (PSEUDO_DOUBLE); }

    if (isChar(literal)) { return (CHAR); }
}

// Convert function
void    ScalarConverter::convert(std::string literal) {
    int type = setType(literal);
}