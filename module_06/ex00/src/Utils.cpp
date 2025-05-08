/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:33:35 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/08 22:05:42 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Check Type
bool    ScalarConverter::isChar(std::string& literal) {
    return (literal.length() == 1 && std::isalpha(literal[0]));
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


// Print values
void    ScalarConverter::print(char c, long i, float f, double d) {
    // Char
    std::cout << "char: ";
    if (i < 0 || i > 127) { std::cout << "impossible\n"; }

    else if (!std::isprint(c)) { std::cout << "Non displayable\n"; }

    else { std::cout << "'" << c << "'" << '\n'; }

    // Int
    std::cout << "int: ";
    if (i < INT_MIN || i > INT_MAX ) { std::cout << "impossible\n"; }

    else { std::cout << static_cast<int>(i) << '\n'; }

    // Float
    std::cout << "float: ";
    std::cout << std::fixed << std::setprecision(1) << f << "f\n";

    // Double
    std::cout << "double: ";
    std::cout << std::fixed << std::setprecision(1) << d << '\n';
}
