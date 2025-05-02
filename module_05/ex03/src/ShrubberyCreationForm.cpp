/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:30:35 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/02 13:18:20 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("target") { 
    std::cout << "ShrubberyCreationForm default constructor called\n"; 
}

// Custom constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) { 
    std::cout << "ShrubberyCreationForm " << this->_target << " constructor called\n"; 
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(other), _target(other._target) {
    std::cout << "ShrubberyCreationForm copy constructor called\n"; 
}

// Copy assignment operator
ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    std::cout << "ShrubberyCreationForm copy assignment operator called\n";
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return (*this);
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() { std::cout << "ShrubberyCreationForm default destructor called\n";  }

// Form execution
void ShrubberyCreationForm::executeAction() const {
    std::ofstream output((this->_target + "_shrubbery").c_str());
    if (!output) {
        std::cerr << "Error: cannot create output file\n"; return ;
    }

    output <<   "       _-_\n"
                "    /~~   ~~\\\n"
                " /~~         ~~\\\n"
                "{               }\n"
                " \\  _-     -_  /\n"
                "   ~  \\\\ //  ~\n"
                "_- -   | | _- _\n"
                "  _ -  | |   -_\n"
                "       | |\n";
}
