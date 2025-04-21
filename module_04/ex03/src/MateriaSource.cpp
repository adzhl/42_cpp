/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:00:01 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/21 13:10:23 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Constructor
MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        this->_templates[i] = NULL;
    std::cout << "MateriaSource default constructor called\n";
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int i = 0; i < 4; i++) {
        if (other._templates[i] != NULL)
            this->_templates[i] = other._templates[i]->clone();
        else
            this->_templates[i] = NULL;
    }
    std::cout << "MateriaSource copy constructor called\n";
}

// Copy assignment operator
MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    std::cout << "MateriaSource copy assignment operator called\n";
    if (this != &other) {
        for (int i = 0; i < 4; i++)
        {
            if (this->_templates[i]) {
                delete _templates[i];
                _templates[i] = NULL;
            }
        }
        for (size_t i = 0; i < 4; i++)
        {
            if (other._templates[i])
                this->_templates[i] = other._templates[i]->clone();
        }
    }
    return (*this);
}

// Destructor
MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++)
        delete this->_templates[i];
    std::cout << "MateriSource destructor called\n"; 
}

void    MateriaSource::learnMateria(AMateria* m) {
    if (!m) { return; }

    for (int i = 0; i < 4; i++) {
        if (this->_templates[i] == NULL) {
            this->_templates[i] = m;
            std::cout << YELLOW << "Learned new materia: " << m->getType() << '\n' << RESET;
            return;
        }
    }
    std::cout << RED << "Inventory full. Cannot learn more materia!\n" << RESET;
}

AMateria*   MateriaSource::createMateria(std::string const& type) {
    for (int i = 0; i < 4; i++) {
        if (this->_templates[i] && this->_templates[i]->getType() == type)
            return (this->_templates[i]->clone());
    }
    std::cout << RED << "Unknown Materia: " << type << '\n' << RESET;
    return (NULL);
}
