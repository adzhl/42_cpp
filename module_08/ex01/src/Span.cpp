/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:26:34 by abinti-a          #+#    #+#             */
/*   Updated: 2025/06/02 10:28:31 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other) { *this = other; }

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _data = other._data;
    }
    return (*this);
}

Span::~Span() {}

unsigned int Span::size() const { return (_data.size()); }

std::vector<int>& Span::getNumbers() { return (_data); }

void Span::addNumber(int num) {
    if (_data.size() >= _maxSize) { throw Span::FullSpanException(); }

    _data.push_back(num);
}

// adjacent_difference : find difference between each pair
// [ a0, (a1 - a0), (a2 - a1), ..., (aN - aN-1) ] 
int Span::shortestSpan() const {
    if (_data.size() < 2)
        throw Span::NotEnoughElementsException();;

    std::vector<int> sorted = _data;
    std::sort(sorted.begin(), sorted.end());

    std::vector<int> diff(sorted.size());
    std::adjacent_difference(sorted.begin(), sorted.end(), diff.begin());

    int minSpan = *std::min_element(diff.begin() + 1, diff.end());

    return (minSpan);
}

int Span::longestSpan() const {
    if (_data.size() < 2) { throw Span::NotEnoughElementsException(); }

    int min = *std::min_element(_data.begin(), _data.end());
    int max = *std::max_element(_data.begin(), _data.end());
    return (max - min);
}
