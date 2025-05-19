/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:44:00 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/19 09:52:10 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>

class Span {
    private:
        unsigned int        _maxSize;
        std::vector<int>    _data;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void            addNumber(int n);
        int             shortestSpan() const;
        int             longestSpan() const;

        unsigned int    size() const;

        template <typename Iterator>
        void            addRange(Iterator begin, Iterator end) {
            if (static_cast<unsigned int>(std::distance(begin, end)) + _data.size() > _maxSize)
                throw std::out_of_range("Not enough space to add range");
            _data.insert(_data.end(), begin, end);
        }

        class FullSpanException : public std::exception {
            public:
                const char* what() const throw() { return ("Span is full. Cannot add more numbers!"); }
        } ;

        class NotEnoughElementsException : public std::exception {
            public:
                const char* what() const throw() { return ("Not enough elements to find a span!"); }
        } ;
} ;

#endif