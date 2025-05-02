/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:32:30 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/02 14:33:17 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("target") { 
    std::cout << "PresidentialPardonForm default constructor called\n"; 
}

// Custom constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) { 
    std::cout << "PresidentialPardonForm " << this->_target << " constructor called\n"; 
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: AForm(other), _target(other._target) {
    std::cout << "PresidentialPardonForm copy constructor called\n"; 
}

// Copy assignment operator
PresidentialPardonForm&  PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    std::cout << "PresidentialPardonForm copy assignment operator called\n";
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return (*this);
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() { std::cout << "PresidentialPardonForm default destructor called\n";  }

// Form execution
void PresidentialPardonForm::executeAction() const {
    std::cout << GREEN << "\n< < " << this->_target << " has been pardoned by Zaphod Beeblebrox > >\n\n" << RESET;
}
