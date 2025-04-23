/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:23:09 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/23 09:53:46 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const int size = 6;
    const Animal* zoo[size];

    std::cout << YELLOW << "\nCreating Animals:\n" << RESET;
    for (int i = 0; i < size; ++i) {
        if (i < size / 2)
            zoo[i] = new Dog();
        else
            zoo[i] = new Cat();
    }

    std::cout << YELLOW << "\nDestroying Animals:\n" << RESET;
    for (int i = 0; i < size; ++i)
        delete zoo[i];

    std::cout << YELLOW << "\nCopy constructor test:\n"<< RESET;
    // Animal animal1;
    // Animal animal2 = animal1;

    Cat cat1;
    Cat cat2 = cat1;

    Dog dog1;
    Dog dog2 = dog1;

    std::cout << YELLOW << "\nDeep copy test:\n"<< RESET;

    Dog basic;
    {
        Dog tmp = basic;
        tmp.setIdea(0, "I got that dawg in me");

        std::cout << "\nBasic idea: " << basic.getIdea(0) << '\n';
        std::cout << "Tmp idea: " << tmp.getIdea(0) << '\n';
    }

    std::cout << "Basic idea after tmp destroyed: " << basic.getIdea(0) << "\n\n";

    std::cout << YELLOW << "Instantiable Test:\n" << RESET;
    // Animal a1;
    // Animal *a2 = new Animal();

    Animal *c1 = new Cat();
    c1->makeSound();

    Animal *d1 = new Dog();
    d1->makeSound();

    std::cout << YELLOW << "\nDestroying Instantiable Animals:\n" << RESET;
    delete c1;
    delete d1;

    std::cout << YELLOW << "\nDestroying Other Animals: (if any)\n" << RESET;
    return (0);
}

// Shallow Copy
// object's non-pointer data is copied
// pointer member just copies the pointer (not the data it points to)
// both objects now share the same memory for the pointed data
// share the same pointer/memory so deleting one will cause dangling pointer (invalid memory for the other pointer)
// _brain = other.brain;

// Deep Copy
// the whole object is duplicated
// for pointer, a new copy of the data is created and assigned a new pointer
// No shared ownership (own memory)
// _brain = new Brain(*other._brain);


// Base class can only see the base portion
// if base has virtual functions, it can still be overidden by derived class version using vtable
// polymorphism treats derived classes as if they're the base class
// a derived class hass all the members of the base class so it can be treated as the base class (store in a base class pointer)
// the base class can only see base class related members in the derived class

// Base* p = new Derived
// p is a base class pointer pointing to a derived class object
// This is called upcasting