/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:55:23 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/05 09:38:12 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

// define type for form-creation function pointer
typedef AForm* (*FormCreator)(const std::string& target);

class Intern {
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        AForm*  makeForm(std::string name, std::string target);

        class   UnknownFormException : public std::exception {
            public:
                const char* what() const throw();
        } ;
} ;

#endif