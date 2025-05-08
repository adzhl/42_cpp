/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:57:27 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/08 13:30:40 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base() {}

Base* generate() {
    int random = rand() % 3;

    switch (random) {
        case 0: return new A;

        case 1: return new B;

        default: return new C;
    }
}

// casting Base* to a Derived*
void    identify(Base* p) {
    if (dynamic_cast<A*>(p)) std::cout << "Base pointer: A\n";

    else if (dynamic_cast<B*>(p)) std::cout << "Base pointer: B\n";

    else if (dynamic_cast<C*>(p)) std::cout << "Base pointer: C\n";
}

// casting Base& to a Derived&
// we are not using the result of dynamic cast, only checking
// hence, we cast (void) to ignore the result
void    identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Base reference: A\n";
        return ;
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Base reference: B\n";
        return ;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Base reference: C\n";
        return ;
    } catch (...) {}
}
