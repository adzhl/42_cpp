/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:02:15 by abinti-a          #+#    #+#             */
/*   Updated: 2025/06/10 13:03:05 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T>
void    printContainer(T& container) {
    std::cout << "{ ";

    typename T::iterator lastElem = --container.end();

    for (typename T::iterator i = container.begin(); i != container.end(); ++i) {
        std::cout << *i;

        if (i != lastElem)
            std::cout << ", ";
    }
    std::cout << " }\n";
}

// insert() : returns std::pair<iterator, bool>
//          : iterator -> position of mentioned number
//          : bool -> whether it has existed yet
// .second : returns (true) if number hasn't existed
template <typename Container1, typename Container2>
void    PmergeMe::validInput(const std::vector<std::string>& input, Container1& c1, Container2& c2) {
    std::set<int> check;

    for (size_t i = 0; i < input.size(); ++i) {
        const std::string& arg = input[i];

        if (arg.empty()) throw std::runtime_error("Error: empty argument");

        if (arg.find_first_not_of("0123456789-") != std::string::npos) throw std::runtime_error("Error: non-numeric character");

        std::istringstream iss(arg);
        long num;
        iss >> num;
        if (iss.fail()) throw std::runtime_error("Error: istringstream failed");

        else if (num < 0 || num > INT_MAX) throw std::runtime_error("Error: non-positive integer");

        if (!check.insert(static_cast<int>(num)).second) throw std::runtime_error("Error: duplicate numbers");

        c1.push_back(num);
        c2.push_back(num);
    }
    std::cout << "Container 1: ";
    printContainer(c1);
    std::cout << "\nContainer 2: ";
    printContainer(c2);
}

template <typename Container1, typename Container2>
void  PmergeMe::sortTime(Container1& c1, Container2& c2) {
    clock_t startC1 = clock();
    (void)c1;
    std::cout << "Sorting c1 should be done here\n";
    clock_t endC1 = clock();

    clock_t startC2 = clock();
    (void)c2;
    std::cout << "Sorting c2 should be done here\n";
    clock_t endC2 = clock();

    double timeC1 = (static_cast<double>(endC1 - startC1) / CLOCKS_PER_SEC * 1000000);
    double timeC2 = (static_cast<double>(endC2 - startC2) / CLOCKS_PER_SEC * 1000000);

    std::cout << std::fixed;
    std::cout << "Time to process a range of " << c1.size() << " elements with std::vector : " << timeC1 << " us\n";
    std::cout << "Time to process a range of " << c2.size() << " elements with std::list : " << timeC2 << " us\n";
}


