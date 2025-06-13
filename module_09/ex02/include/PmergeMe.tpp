/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:02:15 by abinti-a          #+#    #+#             */
/*   Updated: 2025/06/13 18:55:10 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename Container>
bool isSorted(Container& container) {
    if (container.size() < 2) return (true);

    typename Container::const_iterator prev = container.begin();
    typename Container::const_iterator next = prev;
    ++next;

    while (next != container.end()) {
        if (*next < *prev) {
            return (false);
        }
        ++next;
        ++prev;
    }
    return (true);
}

template <typename T>
void    printContainer(T& container) {
    typename T::iterator lastElem = --container.end();

    for (typename T::iterator i = container.begin(); i != container.end(); ++i) {
        std::cout << *i;

        if (i != lastElem)
            std::cout << " ";
    }
    std::cout << "\n";
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
    std::cout << YELLOW << "Before: " << RESET;
    printContainer(c1);
    isSorted(c1) ? std::cout << GREEN << "Sorted!\n" << RESET : std::cout << RED << "Not sorted!\n" << RESET;
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
    clock_t endC2 = clock();

    double timeC1 = (static_cast<double>(endC1 - startC1) / CLOCKS_PER_SEC * 1000000);
    double timeC2 = (static_cast<double>(endC2 - startC2) / CLOCKS_PER_SEC * 1000000);

    std::cout << YELLOW << "After: " << RESET;
    printContainer(c1);
    isSorted(c1) ? std::cout << GREEN << "Sorted!\n" << RESET : std::cout << RED << "Not sorted!\n" << RESET;
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

    bool hasStraggler = (container.size() % 2 != 0);
    int straggler = hasStraggler ? container.back() : 0;

    std::vector<std::pair<int, int> > pairs;
    size_t pairCount = container.size() / 2;
    for (size_t i = 0; i < pairCount; ++i) {
        comparisonCount++;
        if (container[i * 2] < container[i * 2 + 1]) { pairs.push_back(std::make_pair(container[i * 2], container[i * 2 + 1])); }

        else { pairs.push_back(std::make_pair(container[i * 2 + 1], container[i * 2])); }
    }

    // sort pairs here (2 pairs, 4 pairs, 8 pairs and so on)
    // std::sort(pairs.begin(), pairs.end())

    Container main;
    for (size_t i = 0; i < pairs.size(); ++i) {
        main.push_back(pairs[i].second);
    }

    std::cout << "Main: ";
    printContainer(main);

    mergeInsertSort(main);

    Container pend;
    for (size_t i = 0; i < pairs.size(); ++i) {
        pend.push_back(pairs[i].first);
    }

    std::cout << "Pend size: " << pend.size() << '\n';

    // if (container.size() % 2 != 0)
    //     pend.push_back(container.back());

    std::cout << "Pend: ";
    printContainer(pend);

    Container sorted = main;
    if (!pend.empty()) {
        insertSorted(sorted, pend[0]);
        // std::cout << "current sorted after pend[0]: ";
        // printContainer(sorted);

        std::cout << "Pend size: " << pend.size() << '\n';

        if (pend.size() > 1) {
            std::vector<size_t> indices = generateJacobsthalIndices(pend.size() - 1);
            std::cout << "Jacobsthal indices: ";
            printContainer(indices);
            for (size_t i = 0; i < indices.size(); ++i) {
                size_t idx = indices[i] + 1;
                std::cout << "idx = " << idx << '\n';
                if (idx >= pend.size()) continue;

                // std::cout << "pend[idx] = " << pend[idx] << '\n';
                // typename Container::iterator insertPos = std::lower_bound(sorted.begin(), sorted.end(), pend[idx]);
                // comparisonCount += std::distance(sorted.begin(), insertPos); // Count comparisons
                // sorted.insert(insertPos, pend[idx]);
                insertSorted(sorted, pend[idx]);
                std::cout << "current pend: ";
                printContainer(pend);
                std::cout << "current main: ";
                printContainer(main);
                std::cout << "current sorted: ";
                printContainer(sorted);
            }
        }
    }
    if (hasStraggler) {
        insertSorted(sorted, straggler);
    }
    container = sorted;
}

// template <typename Container>
// void PmergeMe::insertSorted(Container& sorted, int value) {
//     typename Container::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
//     sorted.insert(it, value);
// }

// template <typename Container>
// void PmergeMe::mergeInsertSort(Container& container) {
//     if (container.size() <= 1) return;

//     // Create pairs and sort them
//     std::vector<std::pair<int, int> > pairs;
//     bool hasStraggler = (container.size() % 2 != 0);
//     int straggler = hasStraggler ? container.back() : 0;
    
//     // Only pair up even number of elements
//     size_t pairCount = container.size() / 2;
//     for (size_t i = 0; i < pairCount; ++i) {
//         comparisonCount++;
//         if (container[i * 2] < container[i * 2 + 1]) {
//             pairs.push_back(std::make_pair(container[i * 2], container[i * 2 + 1]));
//         } else {
//             pairs.push_back(std::make_pair(container[i * 2 + 1], container[i * 2]));
//         }
//     }

//     // Create main chain (larger elements)
//     Container main;
//     for (size_t i = 0; i < pairs.size(); ++i) {
//         main.push_back(pairs[i].second);
//     }

//     std::cout << "Main: ";
//     printContainer(main);
    
//     // Recursively sort main chain
//     mergeInsertSort(main);

//     // Create pend chain (smaller elements) - DON'T include straggler here
//     Container pend;
//     for (size_t i = 0; i < pairs.size(); ++i) {
//         pend.push_back(pairs[i].first);
//     }

//     std::cout << "Pend: ";
//     printContainer(pend);
//     if (hasStraggler) {
//         std::cout << "Straggler: " << straggler << std::endl;
//     }

//     // Start with main chain as sorted
//     Container sorted = main;
//     std::cout << BLUE << "initial. sorted. SIZE: " << sorted.size() << '\n' << RESET;
    
//     if (!pend.empty()) {
//         // Insert first element of pend (it's guaranteed to be smallest)
//         insertSorted(sorted, pend[0]);
//         std::cout << "after insert pend[0]. sorted. SIZE: " << sorted.size() << '\n';

//         // Generate Jacobsthal indices for remaining pend elements
//         if (pend.size() > 1) {
//             std::vector<size_t> indices = generateJacobsthalIndices(pend.size() - 1);
//             std::cout << "Jacobsthal indices: ";
//             printContainer(indices);
            
//             for (size_t i = 0; i < indices.size(); ++i) {
//                 size_t idx = indices[i] + 1; // +1 because we skip pend[0]
//                 if (idx >= pend.size()) continue;

//                 std::cout << "idx = " << idx << " (inserting pend[" << idx << "] = " << pend[idx] << ")\n";
//                 insertSorted(sorted, pend[idx]);
//             }
//         }
//     }
    
//     // Handle straggler separately
//     if (hasStraggler) {
//         std::cout << "Inserting straggler: " << straggler << '\n';
//         insertSorted(sorted, straggler);
//     }
//     container = sorted;
// }

