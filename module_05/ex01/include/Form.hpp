/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:52:45 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/02 09:36:31 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class Form {
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExecute;

    public:
        Form();
        Form(const std::string name, const int gradeToSign, const int gradeToExecute);
        Form(const Form& other);
        Form&   operator=(const Form& other);
        ~Form();

        // Getter
        const std::string&  getName() const;
        bool                getIsSigned() const;
        int                 getGradeToSign() const;
        int                 getGradeToExecute() const;

        void    beSigned(Bureaucrat& bureaucrat);

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        } ;

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        } ;
} ;

std::ostream&               operator<<(std::ostream& os, const Form& form);

#endif