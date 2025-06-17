/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 09:51:21 by abinti-a          #+#    #+#             */
/*   Updated: 2025/06/17 14:57:56 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"

# include <iostream>
# include <vector>
# include <sstream>
# include <climits>
# include <set>
# include <deque>
# include <cmath>
# include <algorithm>

class PmergeMe {
    private:
        int comparisonCount;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        int getComparisonCount() const;

        template <typename Container1, typename Container2>
        void    validInput(const std::vector<std::string>& input, Container1& c1, Container2& c2);

        template <typename Container1, typename Container2>
        void    sortTime(Container1& c1, Container2& c2);

        template <typename Container>
        void    mergeInsertSort(Container& container, int& comparisonCount);

        template <typename Container>
        void    insertSorted(Container& sorted, int value);

} ;

int                maxComparison(int argc);
std::vector<size_t> generateJacobsthalIndices(size_t n);
// int      jacobsthal(int n);

# include "PmergeMe.tpp"

#endif