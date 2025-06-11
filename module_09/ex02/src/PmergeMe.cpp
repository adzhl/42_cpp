/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 09:53:02 by abinti-a          #+#    #+#             */
/*   Updated: 2025/06/11 15:14:20 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) { *this = other; }

PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return (*this); }

PmergeMe::~PmergeMe() {}


int maxComparison(int argc) {
    int sum = 0;
    for (int k = 1; k <= argc; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return (sum);
}


//         Jn = (2^(n+1) + (-1)^n) / 3
unsigned long jacobsthal(int n) {
    return ((1 << (n + 1)) + (n % 2 == 0 ? 1 : -1)) / 3; 
}