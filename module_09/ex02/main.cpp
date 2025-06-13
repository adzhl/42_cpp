/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 09:51:17 by abinti-a          #+#    #+#             */
/*   Updated: 2025/06/13 17:22:16 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 2) { std::cerr << RED << "Error: no input given!\n" << RESET;  return (1); }

    try {
        PmergeMe sort;
        std::vector<int> vec;
        std::deque<int> deq;

        std::vector<std::string> args(argv + 1, argv + argc);
        sort.validInput(args, vec, deq);
        sort.sortTime(vec, deq);
        std::cout << "No of comparisons: " << sort.getComparisonCount() << '\n';
        std::cout << "Max number of comparisons allowed: " << maxComparison(argc - 1) << '\n';
    }
    catch(const std::exception &e) {
        std::cerr << RED << e.what() << '\n' << RESET;
        return (1);
    }

    return (0);
}

// std::vector<size_t> generateJacobsthalIndices(size_t n) {
//     std::vector<size_t> result;
//     if (n == 0) return result;

//     // Generate Jacobsthal numbers: 1, 1, 3, 5, 11, 21, 43...
//     std::vector<size_t> jacobsthal;
//     if (n >= 1) jacobsthal.push_back(1);
//     if (n >= 1) jacobsthal.push_back(1);
    
//     size_t a = 1, b = 1;
//     while (true) {
//         size_t next = b + 2 * a;
//         if (next > n) break;
//         jacobsthal.push_back(next);
//         a = b;
//         b = next;
//     }

//     // Generate insertion order
//     size_t prev_jacob = 0;
    
//     for (size_t i = 1; i < jacobsthal.size(); ++i) {
//         size_t current_jacob = jacobsthal[i];
        
//         // Clamp to available range
//         size_t end_pos = std::min(current_jacob, n);
        
//         // Insert from end_pos down to prev_jacob + 1 (in descending order)
//         for (size_t pos = end_pos; pos > prev_jacob; --pos) {
//             result.push_back(pos - 1); // Convert to 0-based index
//         }
        
//         prev_jacob = current_jacob;
//     }
    
//     // Handle remaining elements if any
//     for (size_t pos = n; pos > prev_jacob; --pos) {
//         result.push_back(pos - 1); // Convert to 0-based index
//     }

//     return result;
// }

// int main() {
//     // (void)argc;
//     std::vector<size_t> indices = generateJacobsthalIndices(12);
//     printContainer(indices);
//     return (0);
// }
