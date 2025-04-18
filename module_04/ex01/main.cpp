/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:23:09 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/18 10:35:53 by abinti-a         ###   ########.fr       */
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

    std::cout << YELLOW << "\nDeep copy test:\n"<< RESET;
    Dog original;
    original.makeSound();

    Dog copy = original;
    copy.makeSound();

    Dog assigned;
    assigned = original;

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