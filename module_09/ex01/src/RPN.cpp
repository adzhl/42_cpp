/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:27:59 by abinti-a          #+#    #+#             */
/*   Updated: 2025/06/06 09:26:02 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) { *this = other; }

RPN&    RPN::operator=(const RPN& other) { (void)other; return (*this); }

RPN::~RPN() {}



bool RPN::validOperator(char c) const { return (c == '+' || c == '-' || c == '*' || c == '/'); }

bool RPN::validToken(char c) const { return ((c >= '0' && c <= '9' )|| validOperator(c) || c == ' '); }

int RPN::handleOperation(char op, int a, int b) const {
    switch(op) {
        case '+': return (a + b);
        case '-': return (a - b);
        case '*': return (a * b);
        case '/':
            if (b == 0) throw std::runtime_error("Error: Division by zero");
            return (a / b);

        default: throw std::runtime_error("Error: Invalid operator");
    }
}

int RPN::evaluate(const std::string& expression) {
    std::stack<int> stack;

    for (size_t i = 0; i < expression.size(); ++i) {
        char c = expression[i];

        if (!validToken(c)) { throw std::runtime_error("Error: Invalid character in expression"); }

        if (c == ' ') continue;

        if (c >= '0' && c <= '9') { stack.push(c - '0'); }
        else if (validOperator(c)) {
            if (stack.size() < 2) { throw std::runtime_error("Error: Not enough operands for operation"); }
            
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();

            stack.push(handleOperation(c, a, b));
        }
    }
    if (stack.size() != 1) { throw std::runtime_error("Error: Invalid expression format"); }

    return (stack.top());
}
