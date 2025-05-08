/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:05:55 by abinti-a          #+#    #+#             */
/*   Updated: 2025/05/08 13:27:22 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main() {
    srand(clock());

    Base* obj = generate();

    std::cout << "identify(Base*): ";
    identify(obj);

    std::cout << "identify(Base&): ";
    identify(*obj);

    delete obj;

    return (0);
}
