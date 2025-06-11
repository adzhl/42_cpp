/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 09:51:17 by abinti-a          #+#    #+#             */
/*   Updated: 2025/06/11 12:55:24 by abinti-a         ###   ########.fr       */
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
        std::cout << "No of argc: " << argc - 1 << '\n';
        std::cout << "Max number of comparisons allowed: " << maxComparison(argc - 1) << '\n';
    }
    catch(const std::exception &e) {
        std::cerr << RED << e.what() << '\n' << RESET;
        return (1);
    }

    return (0);
}
