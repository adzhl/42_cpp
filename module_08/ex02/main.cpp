/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:10:58 by abinti-a          #+#    #+#             */
/*   Updated: 2025/06/02 11:27:57 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"
#include <list>

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define YELLOW  "\033[33m"

template <typename T>
void    printContainer(T& container) {
    std::cout << "{ ";

    typename T::iterator lastElem = --container.end();

    for (typename T::iterator i = container.begin(); i != container.end(); ++i) {
        std::cout << *i;

        if (i != lastElem)
            std::cout << ", ";
    }
    std::cout << " }\n";
}

void constructorTest() {
    std::cout << YELLOW << "=== CONSTRUCTOR TEST ===" << RESET << '\n';
    std::cout << YELLOW << "Default Constructor:" << RESET << '\n';
    MutantStack<int> def;
    std::cout << "Default constructor size: " << def.size() << '\n';

    std::cout << YELLOW << "\nCopy Constructor:" << RESET << '\n';
    MutantStack<int> ori;
    ori.push(30);
    ori.push(24);
    ori.push(32);
    MutantStack<int> copy(ori);
    MutantStack<int> another = copy;

    std::cout << "Size of copy: " << copy.size() << '\n';
    std::cout << "Top in copy: " << copy.top() << '\n';
    std::cout << "Size of another: " << another.size() << '\n';
    std::cout << "Top in another: " << another.top() << '\n';
}

int main() {
    constructorTest();
    
    std::cout << YELLOW << "\n=== MutantStack Test ===\n" << RESET;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    printContainer(mstack);

    std::cout << "Top element: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "\nAdding more elements: ";
    printContainer(mstack);

    std::cout << "\nIterating MutantStack:\n";
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << YELLOW << "\n=== Comparison with std::list ===\n" << RESET;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);

    printContainer(lst);
    std::cout << "Top Element: " << lst.front() << '\n';
    std::cout << "Last Element: " << lst.back() << '\n';

    lst.pop_back();
    std::cout << "Size after pop: " << lst.size() << '\n';

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << "\nAdding more elements: ";
    printContainer(lst);
    for (std::list<int>::iterator lit = lst.begin(); lit != lst.end(); ++lit)
        std::cout << *lit << std::endl;

    return 0;
}