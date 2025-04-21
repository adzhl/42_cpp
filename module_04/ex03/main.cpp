/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:47:26 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/21 18:09:10 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

void    basicTest() {
    std::cout << BLUE << "\n=== BASIC TEST ===\n\n" << RESET;

    std::cout << BLUE << "--- Creating Materia ---\n" << RESET;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << BLUE << "\n--- Equipping Materia---\n" << RESET;
    ICharacter* me = new Character("me");
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    std::cout << BLUE << "\n--- Using Equipped Materia ---\n" << RESET;
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    std::cout << BLUE << "\n--- Cleanup ---\n" << RESET;
    delete bob;
    delete me;
    delete src;

}

int main() {
    basicTest();
    
    std::cout << BLUE << "\n=== ADDITIONAL TEST ===\n\n" << RESET;
    std::cout << BLUE << "--- Creating Materia ---\n" << RESET;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    AMateria* unknown = src->createMateria("unknown");

    std::cout << BLUE << "\n--- Equipping Materia ---\n" << RESET;
    ICharacter* me = new Character("me");

    // Store allocated materia so we can delete it later
    AMateria* ice1 = src->createMateria("ice");
    AMateria* cure1 = src->createMateria("cure");
    AMateria* ice2 = src->createMateria("ice");
    AMateria* cure2 = src->createMateria("cure");
    AMateria* extra = src->createMateria("ice");

    me->equip(unknown);
    me->equip(ice1);
    me->equip(cure1);
    me->equip(ice2);
    me->equip(cure2);

    // Try equipping 5th (won't be stored), so we delete it manually
    me->equip(extra);
    delete extra;

    std::cout << BLUE << "\n--- Using Equipped Materia ---\n" << RESET;
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    me->use(4, *bob);

    std::cout << BLUE << "\n--- Unequipping Materia ---\n" << RESET;
    me->unequip(2);  // remove ice2 manually after unequipping
    me->use(2, *bob);
    delete ice2;

    std::cout << BLUE << "\n--- Cleanup ---\n" << RESET;
    delete bob;
    delete me;
    delete src;

    return (0);
}
