/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:47:26 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/21 13:10:51 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main()
{
    std::cout << BLUE << "\n=== BASIC TEST ===\n\n" << RESET;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    std::cout << BLUE << "\n---- Destroying objects ----\n" << RESET;
    delete bob;
    delete me;
    delete src;
    
    std::cout << BLUE << "\n=== ADDITIONAL TEST ===\n\n" << RESET;
    
    // Test creating unknown materia
    src = new MateriaSource();
    src->learnMateria(new Ice());
    
    tmp = src->createMateria("unknown");
    if (tmp == NULL)
        std::cout << "Creating unknown materia returned NULL as expected" << std::endl;
    
    // Test full inventory
    me = new Character("me");
    tmp = src->createMateria("ice");
    me->equip(tmp);  // Equip slot 0
    tmp = src->createMateria("ice");
    me->equip(tmp);  // Equip slot 1
    tmp = src->createMateria("ice");
    me->equip(tmp);  // Equip slot 2
    tmp = src->createMateria("ice");
    me->equip(tmp);  // Equip slot 3
    tmp = src->createMateria("ice");
    me->equip(tmp);  // Should not equip (inventory full)
    delete tmp;

    std::cout << BLUE << "\n---Equipped 5 materias (should only store 4) ---\n" << RESET;
    
    // Test using materia from invalid slot
    std::cout << "Using materia from valid slot (0): ";
    me->use(0, *me);
    std::cout << "Using materia from invalid slot (5): ";
    me->use(5, *me);  // Should do nothing
    std::cout << '\n';
    std::cout << "Using materia from invalid slot (-1): ";
    me->use(-1, *me);  // Should do nothing
    std::cout << '\n';
    
    // Test unequipping
    std::cout << "Unequipping slot 1" << std::endl;
    me->unequip(1);
    std::cout << "Using unequipped slot 1: ";
    me->use(1, *me);  // Should do nothing
    
    // Test character copy
    Character* originalChar = new Character("original");
    tmp = src->createMateria("ice");
    originalChar->equip(tmp);
    
    Character* copiedChar = new Character(*originalChar);
    std::cout << "Original character using materia: ";
    originalChar->use(0, *me);
    std::cout << "Copied character using materia: ";
    copiedChar->use(0, *me);
    
    std::cout << BLUE << "\n---- Destroying objects ----\n" << RESET;
    delete copiedChar;
    delete originalChar;
    delete me;
    delete src;
    
    return 0;
}
