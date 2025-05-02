/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:54:22 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/02 17:15:41 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main() {
    try {
        std::cout << YELLOW << "\n=== TEST ===\n" << RESET;

        Intern intern;
        Bureaucrat boss("Boss", 1);

        std::cout << YELLOW << "\n--- Create forms ---\n" << RESET;
        AForm* f1 = intern.makeForm("ShrubberyCreationForm", "Shrubs");
        AForm* f2 = intern.makeForm("RobotomyRequestForm", "Robs");
        AForm* f3 = intern.makeForm("PresidentialPardonForm", "Pres");

        std::cout << YELLOW << "\n--- Shrubbery Creation form ---\n" << RESET;
        boss.signForm(*f1);
        boss.executeForm(*f1);

        std::cout << YELLOW << "\n--- Robotomy Request form ---\n" << RESET;
        boss.signForm(*f2);
        boss.executeForm(*f2);

        std::cout << YELLOW << "\n--- Presidential Pardon form ---\n" << RESET;
        boss.signForm(*f3);
        boss.executeForm(*f3);

        std::cout << YELLOW << "\n--- Destroy forms ---\n" << RESET;
        delete f1;
        delete f2;
        delete f3;
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    return (0);
}
