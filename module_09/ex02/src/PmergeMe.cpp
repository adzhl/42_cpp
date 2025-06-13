/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 09:53:02 by abinti-a          #+#    #+#             */
/*   Updated: 2025/06/12 15:47:58 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : comparisonCount(0) {}

PmergeMe::PmergeMe(const PmergeMe& other) { *this = other; }

PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return (*this); }

PmergeMe::~PmergeMe() {}

int PmergeMe::getComparisonCount() const { return (comparisonCount); }

int maxComparison(int argc) {
    int sum = 0;
    for (int k = 1; k <= argc; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return (sum);
}


//         Jn = (2^(n+1) + (-1)^n) / 3
// int jacobsthal(int n) {
//     return ((1 << (n + 1)) + (n % 2 == 0 ? 1 : -1)) / 3; 
// }

std::vector<size_t> generateJacobsthalIndices(size_t n) {
    std::vector<size_t> result;
    size_t j0 = 0, j1 = 1;

    while (j1 < n) {
        result.push_back(j1);
        size_t next = j1 + 2 * j0;
        j0 = j1;
        j1 = next;
    }

    // Add any missing indices
    for (size_t i = 1; i < n; ++i) {
        if (std::find(result.begin(), result.end(), i) == result.end())
            result.push_back(i);
    }

    return result;
}
