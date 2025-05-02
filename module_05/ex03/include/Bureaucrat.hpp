/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:55:08 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/02 10:57:08 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"

# include <iostream>
# include <string>

class AForm;

class Bureaucrat {
    private:
        const std::string   _name;
        int                 _grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat&    operator=(const Bureaucrat& other);
        ~Bureaucrat();

        const std::string&  getName() const;
        int                 getGrade() const;

        void                incrementGrade();
        void                decrementGrade();

        void                signForm(AForm& form);
        void                executeForm(AForm const& form);

        // nested class inside Bureaucrat
        // belongs to Bureaucrat - Bureaucrat::GradeTooHighException
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        } ;

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        } ;
} ;

// Insertion operator overloader
// How an object of a class should be displayed to the output stream
// friend : can directly access private members of the class
std::ostream&               operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif