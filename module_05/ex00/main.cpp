/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:54:22 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/25 20:53:38 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        std::cout << YELLOW << "\n== OCF TEST===\n" << RESET;

        Bureaucrat mc;
        Bureaucrat tara(mc);
        mc = tara;
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    try {
        std::cout << YELLOW << "\n== NORMAL TEST===\n" << RESET;

        Bureaucrat caleb("Caleb", 1);
        std::cout << GREEN << caleb << '\n' << RESET;

        Bureaucrat sylus("Sylus", 150);
        std::cout << GREEN << sylus << '\n' << RESET;
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    try {
        std::cout << YELLOW << "\n=== GRADE TOO LOW TEST ===\n" << RESET;
        Bureaucrat xavier("Xavier", 151);
        std::cout << GREEN << xavier << '\n' << RESET; // This line will be skipped when there is an exception
    } catch (std::exception &e) {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    try {
        std::cout << YELLOW << "\n=== GRADE TOO HIGH TEST ===\n" << RESET;
        Bureaucrat rafayel("Rafayel", 0);
        std::cout << GREEN << rafayel << '\n' << RESET;
    } catch (std::exception &e) {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    try {
        std::cout << YELLOW << "\n=== INCREMENT TEST ===\n" << RESET;
        Bureaucrat zayne("Zayne", 2);
        std::cout << GREEN << zayne << '\n' << RESET;
        for (int i = 0; i < 5; i++) {
            zayne.incrementGrade();
            std::cout << GREEN << zayne << '\n' << RESET;
        }
    } catch (std::exception &e) {
        std::cout << RED << e.what() << '\n' << RESET;
    }

    try {
        std::cout << YELLOW << "\n=== DECREMENT TEST ===\n" << RESET;
        Bureaucrat mephisto("mephisto", 149);
        std::cout << GREEN << mephisto << '\n' << RESET;
        for (int i = 0; i < 5; i++) {
            mephisto.decrementGrade();
            std::cout << GREEN << mephisto << '\n' << RESET;
        }
    } catch (std::exception &e) {
        std::cout << RED << e.what() << std::endl << RESET;
    }

    return (0);
}
