/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:15:42 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/18 09:10:11 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"

# include <iostream>
# include <string>

class Animal {
    protected:
        std::string _type;

    public:
        Animal();
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        virtual ~Animal();

        const std::string&  getType() const;
        virtual void        makeSound() const;
} ;

#endif

// Why virtual is needed for destructor?
// Destructor is looked up dynamically at runtime 
// To ensure proper cleanup in inheritance when deleting derived class objects via a base class pointer
// with virtual: ~Derived get called then ~Base
// without virtual: only ~Base gets called
// C++ uses static type pointer (Base*) to decide which destructor to call unless virtual

// Virtual function enables runtime polymorphism
// Each class with virtual functions has a vtable (virtual table)
// Each object of the class type has a hidden pointer to the vtable
// When calling a virtual function, the compiler generates a vtable lookup to call the correct function at runtime