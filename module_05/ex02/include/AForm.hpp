/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:57:45 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/02 10:56:48 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class AForm {
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExecute;

    public:
        AForm();
        AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
        AForm(const AForm& other);
        AForm&   operator=(const AForm& other);
        virtual ~AForm();

        // Getter
        const std::string&  getName() const;
        bool                getIsSigned() const;
        int                 getGradeToSign() const;
        int                 getGradeToExecute() const;

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        } ;

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        } ;

        class FormNotSignedException : public std::exception {
            public:
                const char* what() const throw();
        } ;

        void            beSigned(Bureaucrat& bureaucrat);
        void            execute(Bureaucrat const& executor) const;
        virtual void    executeAction() const = 0;
} ;

std::ostream&               operator<<(std::ostream& os, const AForm& form);

#endif