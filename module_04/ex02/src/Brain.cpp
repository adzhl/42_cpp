/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:00:35 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/18 12:35:19 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Constructor
Brain::Brain() { std::cout << "BraiiinZzz...\n"; }

// Copy Constructor
Brain::Brain(const Brain& other) {
    std::cout << "Brain copy constructor called\n";
    *this = other;
}

// Copy assignment operator
Brain&  Brain::operator=(const Brain& other) {
    std::cout << "Brain copy assignment operator called\n";
    if (this != &other) {
        for(int i = 0; i < 100; ++i)
            _ideas[i] = other._ideas[i];
    }
    return (*this);
}

// Destructor
Brain::~Brain() { std::cout << "....no more Braii..in..Z...z..z\n"; }

// Setter
void    Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100)
        this->_ideas[index] = idea;
}

// Getter
std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return (this->_ideas[index]);
    return ("");
}
