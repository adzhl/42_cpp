/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 08:29:06 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/02 09:36:21 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Default constructor
Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1) { 
    std::cout << "Form Default constructor called\n";
}

// Custom constructor
Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) { std::cout << "Form " << this->_name << " constructor called\n";
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

// Copy constructor
Form::Form(const Form& other) 
: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
    std::cout << "Form Copy constructor called\n";
}

// Copy assignment operator
Form&   Form::operator=(const Form& other) {
    std::cout << "Form Copy assignment operator called\n";
    if (this != &other) 
        this->_isSigned = other._isSigned;
    return (*this);
}

Form::~Form() { std::cout << "Form destructor called\n"; }

// Getters
const std::string&  Form::getName() const { return (this->_name); }

bool    Form::getIsSigned() const { return (this->_isSigned); }

int   Form::getGradeToSign() const { return (this->_gradeToSign); }

int   Form::getGradeToExecute() const { return (this->_gradeToExecute); }

// Member function
void    Form::beSigned(Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

// Insertion operator overload
std::ostream&   operator<<(std::ostream& os, const Form& form) {
    os  << BLUE << "Form name: " << form.getName() << '\n'
        << "Form signed?: " << std::boolalpha << form.getIsSigned() << '\n'
        << "Form grade to sign: " << form.getGradeToSign() << '\n'
        << "Form grade to execute: " << form.getGradeToExecute() << '\n' << RESET;
    return (os);
}

// Exceptions
const char*     Form::GradeTooHighException::what() const throw() { return ("Grade too high!"); }

const char*     Form::GradeTooLowException::what() const throw() { return ("Grade too low!"); }
