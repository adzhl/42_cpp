/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:26:34 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/19 10:22:33 by abinti-a         ###   ########.fr       */
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

void Span::addNumber(int num) {
    if (_data.size() >= _maxSize) { throw Span::FullSpanException(); }

    _data.push_back(num);
}

int Span::shortestSpan() const {
    if (_data.size() < 2)
        throw std::logic_error("Not enough elements to find a span.");

    std::vector<int> sorted = _data;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (_data.size() < 2) { throw Span::NotEnoughElementsException(); }

    int min = *std::min_element(_data.begin(), _data.end());
    int max = *std::max_element(_data.begin(), _data.end());
    return (max - min);
}
