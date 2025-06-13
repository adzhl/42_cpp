/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:02:15 by abinti-a          #+#    #+#             */
/*   Updated: 2025/06/12 15:43:06 by abinti-a         ###   ########.fr       */
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

// clock()          : returns CPU time used in clock ticks (system dependent)
// CLOCKS_PER_SEC   : converts ticks to seconds (system dependent)
// 1 second == 1,000,000 microseconds
template <typename Container1, typename Container2>
void  PmergeMe::sortTime(Container1& c1, Container2& c2) {
    clock_t startC1 = clock();
    mergeInsertSort(c1);
    clock_t endC1 = clock();
    std::cout << "Final vector: ";
    printContainer(c1);

    clock_t startC2 = clock();
    // mergeInsertSort(c2);
    // std::cout << "Final deque: ";
    // printContainer(c2);
    clock_t endC2 = clock();

    double timeC1 = (static_cast<double>(endC1 - startC1) / CLOCKS_PER_SEC * 1000000);
    double timeC2 = (static_cast<double>(endC2 - startC2) / CLOCKS_PER_SEC * 1000000);

    std::cout << std::fixed;
    std::cout << "Time to process a range of " << c1.size() << " elements with std::vector : " << timeC1 << " us\n";
    std::cout << "Time to process a range of " << c2.size() << " elements with std::deque : " << timeC2 << " us\n";
}

template <typename Container>
void PmergeMe::insertSorted(Container& sorted, int value) {
    typename Container::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(it, value);
}

template <typename Container>
void PmergeMe::mergeInsertSort(Container& container) {
    if (container.size() <= 1) return;

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < container.size() - 1; i += 2) {
        comparisonCount++;
        if (container[i] < container[i + 1]) { pairs.push_back(std::make_pair(container[i], container[i + 1])); }

        else { pairs.push_back(std::make_pair(container[i + 1], container[i])); }
    }

    Container main;
    for (size_t i = 0; i < pairs.size(); ++i) {
        main.push_back(pairs[i].second);
    }

    if (container.size() % 2 != 0)
        main.push_back(container.back());
    std::cout << "Main: ";
    printContainer(main);
    mergeInsertSort(main);

    Container pend;
    for (size_t i = 0; i < pairs.size(); ++i) {
        pend.push_back(pairs[i].first);
    }

    std::cout << "Pend: ";
    printContainer(pend);

    Container sorted = main;
    if (!pend.empty()) {
        // Insert first pend directly (always index 0)
        typename Container::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), pend[0]);
        comparisonCount += std::distance(sorted.begin(), pos); // Count comparisons in lower_bound
        sorted.insert(pos, pend[0]);

        // Use Jacobsthal to insert remaining
        std::vector<size_t> indices = generateJacobsthalIndices(pend.size());
        for (size_t i = 1; i < indices.size(); ++i) {
            size_t idx = indices[i];
            if (idx >= pend.size()) continue;

            typename Container::iterator insertPos = std::lower_bound(sorted.begin(), sorted.end(), pend[idx]);
            comparisonCount += std::distance(sorted.begin(), insertPos); // Count comparisons
            sorted.insert(insertPos, pend[idx]);
        }
    }

    container = sorted;
}