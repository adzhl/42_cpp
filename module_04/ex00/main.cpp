/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:23:09 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/18 14:49:09 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << BLUE << "\n=== ANIMAL TEST ===\n" << RESET;

    std::cout << YELLOW << "\n=== Creating Animals ===\n" << RESET;
    const Animal* meta = new Animal();  // const to ensure object cannot be modified
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << YELLOW << "\n=== Get Type ===\n" << RESET;
    std::cout << j->getType() << '\n';
    std::cout << i->getType() << '\n';
    std::cout << meta->getType() << '\n';

    std::cout << YELLOW << "\n=== Making Sounds ===\n" << RESET;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << YELLOW << "\n=== Destroying Animals ===\n" << RESET;
    delete meta;
    delete j;
    delete i;

    std::cout << BLUE << "\n=== WRONG ANIMAL TEST ===\n" << RESET;

    std::cout << YELLOW << "\n=== Creating Wrong Animals ===\n" << RESET;
    const WrongAnimal* wrong_meta = new WrongAnimal();
    const WrongAnimal* wrong_i = new WrongCat();

    std::cout << YELLOW << "\n=== Get Wrong Type ===\n" << RESET;
    std::cout << wrong_i->getType() << '\n';
    std::cout << wrong_meta->getType() << '\n';

    std::cout << YELLOW << "\n=== Making Wrong Sounds ===\n" << RESET;
    wrong_i->makeSound();
    wrong_meta->makeSound();

    std::cout << YELLOW << "\n=== Destroying Wrong Animals ===\n" << RESET;
    delete wrong_meta;
    delete wrong_i;

    std::cout << BLUE << "\n=== COPY CONSTRUCTOR TEST ===\n" << RESET;
    Animal a1;
    Animal a2 = a1;
    std::cout << '\n';

    Cat c1;
    Cat c2 = c1;
    std::cout << '\n';

    Dog d1;
    Dog d2 = d1;
    std::cout << '\n';

    return (0);
}

// Base class can only see the base portion
// if base has virtual functions, it can still be overidden by derived class version using vtable
// polymorphism treats derived classes as if they're the base class
// a derived class hass all the members of the base class so it can be treated as the base class (store in a base class pointer)
// the base class can only see base class related members in the derived class

// Base* p = new Derived
// p is a base class pointer pointing to a derived class object
// This is called upcasting