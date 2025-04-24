/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:54:47 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/24 11:35:29 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : _name("Some fella"), _grade(1) { std::cout << "Bureaucrat default constructor called\n"; }

// Custom constructor
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) { 
    std::cout << "Bureaucrat " << this->_name << " constructor called\n";
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) { std::cout << "Bureaucrat copy constructor called\n"; }

// Copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Bureaucrat copy assignment operator called\n";
    if (this != &other)
        this->_grade = other._grade;
    return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat() { std::cout << "Bureaucrat destructor called\n"; }

// Getter for name
const std::string&  Bureaucrat::getName() const { return (this->_name); }

// Getter for grade
int Bureaucrat::getGrade() const { return (this->_grade); }

// Increment grade
void    Bureaucrat::incrementGrade() {
    if (this->_grade > 1)
        this->_grade--;
    else
        throw Bureaucrat::GradeTooHighException();
}

// Decrement grade
void    Bureaucrat::decrementGrade() {
    if (this->_grade < 150)
        this->_grade++;
    else
        throw Bureaucrat::GradeTooLowException();
}

// Insertion operator overload
std::ostream&   operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os  << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return (os);
}

// Exception
const char* Bureaucrat::GradeTooHighException::what() const throw() { return ("Bureaucrat grade too high!"); }

const char* Bureaucrat::GradeTooLowException::what() const throw() { return ("Bureaucrat grade too low!"); }
