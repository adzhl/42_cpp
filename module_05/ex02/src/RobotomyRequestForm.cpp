/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:40:25 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/05 08:37:24 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

// Default constructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("target") { 
    std::cout << "RobotomyRequestForm default constructor called\n"; 
}

// Custom constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) { 
    std::cout << "RobotomyRequestForm " << this->_target << " constructor called\n"; 
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other), _target(other._target) {
    std::cout << "RobotomyRequestForm copy constructor called\n"; 
}

// Copy assignment operator
RobotomyRequestForm&  RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    std::cout << "RobotomyRequestForm copy assignment operator called\n";
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return (*this);
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() { std::cout << "RobotomyRequestForm default destructor called\n";  }

// Form execution
// rand()   : returns a pseudo-random integer between 0 - RAND_MAX
// srand()  : sets the seed for rand() - controls the starting point of the random sequence
void RobotomyRequestForm::executeAction() const {
    std::cout << BLUE << "\n* * < SOME DRILLING NOISES > * *\n" << RESET;
    srand(std::time(NULL));
    if (rand() % 2 == 0)
        std::cout << GREEN << this->_target << " has been robotomized successfully\n" << RESET;
    else
        std::cout << RED << "Robotomy for " << this->_target << " failed :(\n" << RESET;
}
