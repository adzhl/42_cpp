/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 08:29:06 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/02 09:36:21 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Default constructor
AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1) { 
    std::cout << "AForm Default constructor called\n";
}

// Custom constructor
AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) { std::cout << "AForm " << this->_name << " constructor called\n";
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

// Copy constructor
AForm::AForm(const AForm& other) 
: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
    std::cout << "AForm Copy constructor called\n";
}

// Copy assignment operator
AForm&   AForm::operator=(const AForm& other) {
    std::cout << "AForm Copy assignment operator called\n";
    if (this != &other) 
        this->_isSigned = other._isSigned;
    return (*this);
}

AForm::~AForm() { std::cout << "AForm destructor called\n"; }

// Getters
const std::string&  AForm::getName() const { return (this->_name); }

bool    AForm::getIsSigned() const { return (this->_isSigned); }

int   AForm::getGradeToSign() const { return (this->_gradeToSign); }

int   AForm::getGradeToExecute() const { return (this->_gradeToExecute); }

// Insertion operator overload
std::ostream&   operator<<(std::ostream& os, const AForm& Aform) {
    os  << BLUE << "AForm name: " << Aform.getName() << '\n'
        << "AForm signed?: " << std::boolalpha << Aform.getIsSigned() << '\n'
        << "AForm grade to sign: " << Aform.getGradeToSign() << '\n'
        << "AForm grade to execute: " << Aform.getGradeToExecute() << '\n' << RESET;
    return (os);
}

// Exceptions
const char*     AForm::GradeTooHighException::what() const throw() { return ("Grade too high!"); }

const char*     AForm::GradeTooLowException::what() const throw() { return ("Grade too low!"); }

const char*     AForm::FormNotSignedException::what() const throw() { return ("Form not signed!"); }

// Member function
void    AForm::beSigned(Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

void    AForm::execute(Bureaucrat const& executor) const {
    if (!this->_isSigned)
        throw AForm::FormNotSignedException();
    else if (executor.getGrade() > this->_gradeToExecute)
        throw AForm::GradeTooLowException();
    this->executeAction();
}
