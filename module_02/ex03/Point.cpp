/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 07:56:37 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/09 11:47:35 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x_value, const float y_value) : _x(x_value), _y(y_value) {}

Point::Point(const Point& other) : _x(other.getX()), _y(other.getY()) {}

// _x and _y are const so the values cannot be modified
// this copy assignment operator does not assign a new value
// only here due to othordox canonical form requirement
Point& Point::operator=(const Point& other) {
    (void)other;
    return (*this);
}

Point::~Point() {}

const Fixed&    Point::getX() const { return (_x); }

const Fixed&    Point::getY() const { return (_y); }

std::ostream&   operator<<(std::ostream& os, const Point& point) {
    std::cout << "x: " << point.getX() << ", y: " << point.getY();
    return (os);  
}
