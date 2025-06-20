/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 09:51:17 by abinti-a          #+#    #+#             */
/*   Updated: 2025/06/20 11:11:56 by abinti-a         ###   ########.fr       */
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
        if (!sort.validInput(args, vec, deq)) return (0);

        sort.sortTime(vec, deq);
    }
    catch(const std::exception &e) {
        std::cerr << RED << e.what() << '\n' << RESET;
        return (1);
    }

    return (0);
}

// [ Why compare vector with deque? ]
// Both support random access, O(1)
// Vector - contiguous, expensive for large datasets
// Deque - Non-contiguous (chunkss), slower random access, faster at the ends
// Merge insertion sort inserts in the middle

// [ Key aspects of merge insertion]
// The role of pairs help reduce the number of comparisons

// [ Jacobsthal sequence ]
// Determines the optimal insertion order of elements
// It's cheaper in early insertions but get progressively more expensive
// Insert large gaps first
// Reduce average search depth (partially constrained)

// [ Binary insertion ]
// ensures insertion takes O(log k), k = size of main at insertion
