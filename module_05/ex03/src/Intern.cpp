/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:59:38 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/02 16:50:13 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

// Default constructor
Intern::Intern() { std::cout << "Intern default constructor called\n"; }

// Copy constructor
Intern::Intern(const Intern& other) { (void)other; std::cout << "Intern copy constructor called\n"; }

// Copy assignment operator
Intern& Intern::operator=(const Intern& other) { std::cout << "Intern copy assignment operator called\n"; (void)other; return (*this); }

// Destructor
Intern::~Intern() { std::cout << "Intern destructor called\n"; }


// Helper functions
AForm*  createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm*  createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm*  createPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}


// Member function
AForm*  Intern::makeForm(std::string name, std::string target) {
    std::string forms[] = {
        "ShrubberyCreationForm",
        "RobotomyRequestForm",
        "PresidentialPardonForm"
    } ;

    FormCreator create[] = {
        &createShrubbery,
        &createRobotomy,
        &createPresidential,
    } ;

    for (int i = 0; i < 3; ++i) {
        if (name == forms[i]) {
            std::cout << GREEN << "Intern creates " << name << '\n' << RESET;
            return (create[i](target));
        }
    }
    std::cout << RED << "Form does not exist\n" << RESET;
    return (NULL);
}
