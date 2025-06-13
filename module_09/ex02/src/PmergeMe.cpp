/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 09:53:02 by abinti-a          #+#    #+#             */
/*   Updated: 2025/06/13 17:24:36 by abinti-a         ###   ########.fr       */
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


// J(n) = J(n - 1) + 2 * J(n - 2)
// J(0) = 0
// J(1) = 1
// 0, 1, 1, 3, 5, 11, 21, 43
// std::vector<size_t> generateJacobsthalIndices(size_t n) {
//     std::vector<size_t> result;
//     if (n == 0) return result;

//     // Always insert index 0 first (special case)
//     result.push_back(0);
//     if (n == 1) return result;

//     // Generate Jacobsthal numbers (1, 1, 3, 5, 11, 21...)
//     std::vector<size_t> jacob;
//     size_t a = 1, b = 1;  // J1=1, J2=1
//     jacob.push_back(a);
//     jacob.push_back(b);

//     while (true) {
//         size_t next = b + 2 * a;
//         if (next > n) break;
//         jacob.push_back(next);
//         a = b;
//         b = next;
//     }

//     // Generate insertion order (convert to 0-based)
//     for (size_t i = 2; i < jacob.size(); ++i) {
//         size_t current = jacob[i] - 1;    // Convert to 0-based
//         size_t prev = jacob[i-1] - 1;    // Convert to 0-based

//         // Insert current index
//         if (current < n) {
//             result.push_back(current);
//         }

//         // Insert descending indices between current and prev
//         for (size_t k = current - 1; k > prev; --k) {
//             if (k < n) {  // Ensure within bounds
//                 result.push_back(k);
//             }
//         }
//     }

//     return result;
// }

std::vector<size_t> generateJacobsthalIndices(size_t n) {
    std::vector<size_t> result;
    if (n == 0) return result;

    // Generate Jacobsthal numbers: 1, 1, 3, 5, 11, 21, 43...
    std::vector<size_t> jacobsthal;
    if (n >= 1) jacobsthal.push_back(1);
    if (n >= 1) jacobsthal.push_back(1);
    
    size_t a = 1;
    size_t b = 1;
    while (true) {
        size_t next = b + 2 * a;
        if (next > n) break;
        jacobsthal.push_back(next);
        a = b;
        b = next;
    }

    size_t prev_jacob = 0;
    for (size_t i = 1; i < jacobsthal.size(); ++i) {
        size_t current_jacob = jacobsthal[i];
        // Clamp to available range
        size_t end_pos = std::min(current_jacob, n);
        
        // Insert from end_pos down to prev_jacob + 1 (in descending order)
        for (size_t pos = end_pos; pos > prev_jacob; --pos) {
            result.push_back(pos - 1); // Convert to 0-based index
        }
        
        prev_jacob = current_jacob;
    }
    
    // Handle remaining elements if any
    for (size_t pos = n; pos > prev_jacob; --pos) {
        result.push_back(pos - 1); // Convert to 0-based index
    }

    return result;
}

// std::vector<size_t> generateJacobsthalIndices(size_t n) {
//     std::vector<size_t> result;
//     std::vector<size_t> jacobNums;

//     size_t a = 0;
//     size_t b = 1;
//     jacobNums.push_back(0);
//     jacobNums.push_back(1);

//     for (size_t i = 2; ; ++i) {
//         size_t next = (i - 1) + 2 * (i - 2);
//         if (next > n) break;
//         jacobNums.push_back(next);
//     }

//         for (size_t i = 2; i < jacobNums.size(); ++i) {
//         size_t current = jacobNums[i];
//         size_t prev = jacobNums[i-1];

//         // Push current Jacobsthal number first
//         if (current <= n) {
//             result.push_back(current);
//         }

//         // Push numbers in descending order from (current - 1) down to (prev + 1)
//         for (size_t k = current - 1; k > prev; --k) {
//             if (k <= n) {  // Ensure we don't exceed n
//                 result.push_back(k);
//             }
//         }
//     }

//     return result;
// }


// std::vector<size_t> generateJacobsthalIndices(size_t n) {
//     std::vector<size_t> result;
//     std::vector<size_t> jacobNums;

//     size_t a = 0;
//     size_t b = 1;
//     jacobNums.push_back(0);
//     jacobNums.push_back(1);
//     // jacobNums.push_back(1);

//     while (true) {
//         size_t next = b + 2 * a;
//         if (next > n) break;
//         jacobNums.push_back(next);
//         a = b;
//         b = next;
//     }

//     for (size_t i = 2; i < jacobNums.size(); ++i) {
//         size_t current = jacobNums[i];
//         size_t prev = jacobNums[i - 1];

//         for (size_t k = current; k > prev; --k) {
//             if (k <= n)
//                 result.push_back(k);
//         }
//     }

//     return result;
// }


