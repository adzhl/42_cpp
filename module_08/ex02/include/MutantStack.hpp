/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:42:02 by abinti-a          #+#    #+#             */
/*   Updated: 2025/06/02 11:38:25 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>
# include <iterator>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack() : std::stack<T>() {}
        MutantStack(const MutantStack& other) : std::stack<T>(other) {}
        MutantStack&    operator=(const MutantStack& other) {
            std::stack<T>::operator=(other);
            return (*this);
        }
        ~MutantStack() {}

        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        iterator begin() { return (this->c.begin()); }
        iterator end() { return (this->c.end()); }

        const_iterator begin() const { return (this->c.begin()); }
        const_iterator end() const { return (this->c.end()); }

        reverse_iterator rbegin() { return (this->c.rbegin()); }
        reverse_iterator rend() { return (this->c.rend()); }

        const_reverse_iterator rbegin() const { return (this->c.rbegin()); }
        const_reverse_iterator rend() const { return (this->c.rend()); }
} ;

#endif

// stack is a container adaptor (wrapper)
// wraps over an existing container (deque by default)
// restricts access to provide a specific behaviour

// Examples:
// std::stack - LIFO (Last In First Out)
// std::queue -FIFO (First In First Out)

// does not expose iterators or random access (limited interface)
//  - pop()
//  - push()
//  - top()
//  - empty()
//  - size()

// To specify underlying container
// std::stack<int, std::vector<int>> s1;

// 'c' is the protected member in std::stack that stores the internal container