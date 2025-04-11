/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 07:56:26 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/11 09:22:59 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main() {
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(2.5f, 5.0f);

    Point inside(2.5f, 2.0f);
    Point onVertex(0.0f, 0.0f);
    Point outside(5.0f, 5.0f);
    Point onEdge(2.5f, 0.0f);
    Point center(2.5f, 1.666f);
    Point nearlyOutside(2.5f, -0.1f);

    std::cout << "Inside test:        " << (bsp(a, b, c, inside) ? "Inside" : "Not inside") << std::endl;
    std::cout << "On vertex test:     " << (bsp(a, b, c, onVertex) ? "Inside" : "Not inside") << std::endl;
    std::cout << "Outside test:       " << (bsp(a, b, c, outside) ? "Inside" : "Not inside") << std::endl;
    std::cout << "On edge test:       " << (bsp(a, b, c, onEdge) ? "Inside" : "Not inside") << std::endl;
    std::cout << "Near center test:   " << (bsp(a, b, c, center) ? "Inside" : "Not inside") << std::endl;
    std::cout << "Nearly outside test:" << (bsp(a, b, c, nearlyOutside) ? "Inside" : "Not inside") << std::endl;

    return (0);
}
