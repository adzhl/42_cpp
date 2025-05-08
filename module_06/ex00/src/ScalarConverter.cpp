/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:21:36 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/08 09:02:18 by abinti-a         ###   ########.fr       */
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


// Check Type
bool    ScalarConverter::isChar(std::string& literal) {
    return (literal.length() == 1 && std::isalpha(literal[0]));
    //     return (true);
    // return (false);
}

bool    ScalarConverter::isPseudoFloat(std::string& literal) {
    return (literal == "nanf" || literal == "-inff" || literal == "+inff");
}

bool    ScalarConverter::isPseudoDouble(std::string& literal) {
    return (literal == "nan" || literal == "-inf" || literal == "+inf" || literal == "inf");
}

bool    ScalarConverter::isFloat(std::string& literal) {
    if (literal.length() < 2) { return (false); }

    if (literal[literal.length() - 1] != 'f') { return (false); }

    std::string checkDigits = literal.substr(0, literal.length() - 1);

    return (checkNum(checkDigits));
}


// Check if an int, float or double only contains one +/- and digits
// continue : skips remaining code in the loop and go to the next iteration
bool    ScalarConverter::checkNum(std::string& literal) {
    size_t  i = 0;
    bool    decimal = false;

    if (literal[0] == '+' || literal[0] == '-') { 
        i++;
        if (i == literal.length()) { return (false); }
    }

    for (; i < literal.length(); ++i) {
        if (std::isdigit(literal[i])) { continue; }

        else if (literal[i] == '.' && !decimal) { decimal = true; }

        else { return (false); }
    }
    return (true);
}


// Set Type
// find('.') != npos(not found) : if '.' is found in string
int  ScalarConverter::setType(std::string& literal) {
    if (literal.empty()) { return (INVALID); }

    if (isPseudoFloat(literal)) { return (PSEUDO_FLOAT); }

    if (isPseudoDouble(literal)) { return (PSEUDO_DOUBLE); }

    if (isChar(literal)) { return (CHAR); }

    if (isFloat(literal)) { return (FLOAT); }

    if (checkNum(literal)) { return (literal.find('.') != std::string::npos ? DOUBLE : INT); }

    return (INVALID);
}


// Convert function
void    ScalarConverter::convert(std::string literal) {
    int type = setType(literal);

    std::cout << "type: " << type << '\n';
}