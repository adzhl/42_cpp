/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:54:22 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/02 09:44:00 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        std::cout << YELLOW << "\n== OCF TEST ===\n" << RESET;

        Bureaucrat mc;
        Bureaucrat tara(mc);
        mc = tara;

        std::cout << '\n';

        Form tax;
        Form evasion(tax);
        tax = evasion;

        std::cout << '\n'; 
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    try {
        std::cout << YELLOW << "\n== GRADE TO SIGN TEST===\n" << RESET;
        Form fraud("FraudForm", 0, 1);
        std::cout << fraud << '\n';
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    try {
        Form fraud("FraudForm", 151, 1);
        std::cout << fraud << '\n';
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    try {
        std::cout << YELLOW << "\n== GRADE TO EXECUTE TEST===\n" << RESET;
        Form evasion("EvasionForm", 1, 0);
        std::cout << evasion << '\n';
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    try {
        Form evasion("EvasionForm", 1, 151);
        std::cout << evasion << '\n';
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    try {
        std::cout << YELLOW << "\n== SIGN TEST ===\n" << RESET;

        Bureaucrat caleb("Caleb", 1);
        std::cout << GREEN << caleb << '\n' << RESET;

        Bureaucrat sylus("Sylus", 150);
        std::cout << GREEN << sylus << '\n' << RESET;

        Form tax("TaxForm", 75, 65);
        std::cout << tax << '\n';

        caleb.signForm(tax);
        std::cout << '\n';

        sylus.signForm(tax);
        std::cout <<'\n';
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    return (0);
}
