/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:28:04 by abinti-a          #+#    #+#             */
/*   Updated: 2025/06/06 09:07:13 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"

# include <iostream>
# include <stack>
# include <sstream>

class RPN {
    private:
        bool    validOperator(char c) const;
        bool    validToken(char c) const;
        int     handleOperation(char op, int a, int b) const;

    public:
        RPN();
        RPN(const RPN& other);
        RPN&    operator=(const RPN& other);
        ~RPN();

        int evaluate(const std::string& expression);
} ;

#endif