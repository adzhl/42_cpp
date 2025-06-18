/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 09:53:02 by abinti-a          #+#    #+#             */
/*   Updated: 2025/06/18 11:31:07 by abinti-a         ###   ########.fr       */
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

std::vector<size_t> generateJacobsthalIndices(size_t n) {
    std::vector<size_t> result;
    if (n == 0) return result;
    if (n == 1) {
        result.push_back(1);
        return (result);
    }

    std::vector<size_t> jacobsthal;
    if (n >= 1) jacobsthal.push_back(1);
    if (n >= 2) jacobsthal.push_back(3);
    
    size_t a = 1;
    size_t b = 3;
    while (true) {
        size_t next = b + 2 * a;
        if (next > n) break;
        jacobsthal.push_back(next);
        a = b;
        b = next;
    }

    size_t prev_jacob = 1;
    for (size_t i = 1; i < jacobsthal.size(); ++i) {
        size_t current_jacob = jacobsthal[i];
        size_t end_pos = std::min(current_jacob, n);
        
        // Insert from end_pos down to prev_jacob + 1 (in descending order)
        for (size_t pos = end_pos; pos > prev_jacob; --pos) {
            result.push_back(pos); // Convert to 0-based index
        }
        
        prev_jacob = current_jacob;
    }
    
    // Handle remaining elements if any
    for (size_t pos = n; pos > prev_jacob; --pos) {
        result.push_back(pos); // Convert to 0-based index
    }

    return result;
}
