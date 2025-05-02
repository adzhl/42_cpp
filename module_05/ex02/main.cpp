/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:54:22 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/02 14:31:07 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
    try {
        std::cout << YELLOW << "\n=== OCF TEST ===\n" << RESET;

        Bureaucrat mc;
        Bureaucrat tara(mc);
        mc = tara;

        std::cout << '\n';

        ShrubberyCreationForm tax;
        ShrubberyCreationForm evasion(tax);
        tax = evasion;

        std::cout << '\n';

        RobotomyRequestForm identity;
        RobotomyRequestForm fraud(identity);
        identity = fraud;

        std::cout << '\n';

        PresidentialPardonForm money;
        PresidentialPardonForm laundering(money);
        money = laundering;

        std::cout << '\n'; 
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    try {
        std::cout << YELLOW << "\n=== SHRUBBERY CREATION FORM TEST===\n" << RESET;
        std::cout   << BLUE << "\nREQUIRED GRADES \n" 
                    << "--> sign: 145\n" 
                    << "--> execute: 137\n" << RESET;
        std::cout << YELLOW << "\n--- Execute without signing ---\n" << RESET;

        Bureaucrat caleb("Caleb", 137);
        ShrubberyCreationForm wanderer("Wanderer");

        wanderer.execute(caleb);
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    try {
        std::cout << YELLOW << "\n--- Execute with low grade ---\n" << RESET;

        Bureaucrat sylus("Sylus", 145);
        ShrubberyCreationForm wanderer("Wanderer");

        sylus.signForm(wanderer);

        wanderer.execute(sylus);
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    try {
        std::cout << YELLOW << "\n--- Execute with high grade ---\n" << RESET;

        Bureaucrat caleb("Caleb", 137);
        ShrubberyCreationForm wanderer("Wanderer");

        caleb.signForm(wanderer);

        wanderer.execute(caleb);
        std::cout << BLUE << "\n! Look for newly created *_shrubbery file in current directory !\n\n" << RESET;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    try {
        std::cout << YELLOW << "\n=== ROBOTOMY REQUEST FORM TEST===\n" << RESET;
        std::cout   << BLUE << "\nREQUIRED GRADES \n" 
                    << "--> sign: 72\n" 
                    << "--> execute: 45\n" << RESET;
        std::cout << YELLOW << "\n--- Execute without signing ---\n" << RESET;

        Bureaucrat caleb("Caleb", 1);
        RobotomyRequestForm wanderer("Wanderer");

        wanderer.execute(caleb);
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    try {
        std::cout << YELLOW << "\n--- Execute with low grade ---\n" << RESET;

        Bureaucrat sylus("Sylus", 72);
        RobotomyRequestForm wanderer("Wanderer");

        sylus.signForm(wanderer);

        wanderer.execute(sylus);
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    try {
        std::cout << YELLOW << "\n--- Execute with high grade ---\n" << RESET;

        Bureaucrat caleb("Caleb", 45);
        RobotomyRequestForm wanderer("Wanderer");

        caleb.signForm(wanderer);

        wanderer.execute(caleb);
        std::cout << BLUE << "\nRun this program a few times to see the 50% success rate !\n" << RESET;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    try {
        std::cout << YELLOW << "\n=== PRESIDENTIAL PARDON FORM TEST===\n" << RESET;
        std::cout   << BLUE << "\nREQUIRED GRADES \n" 
                    << "--> sign: 25\n" 
                    << "--> execute: 5\n" << RESET;
        std::cout << YELLOW << "\n--- Execute without signing ---\n" << RESET;

        Bureaucrat caleb("Caleb", 1);
        PresidentialPardonForm wanderer("Wanderer");

        wanderer.execute(caleb);
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    try {
        std::cout << YELLOW << "\n--- Execute with low grade ---\n" << RESET;

        Bureaucrat sylus("Sylus", 25);
        PresidentialPardonForm wanderer("Wanderer");

        sylus.signForm(wanderer);

        wanderer.execute(sylus);
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    try {
        std::cout << YELLOW << "\n--- Execute with high grade ---\n" << RESET;

        Bureaucrat caleb("Caleb", 5);
        PresidentialPardonForm wanderer("Wanderer");

        caleb.signForm(wanderer);

        wanderer.execute(caleb);
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    return (0);
}
