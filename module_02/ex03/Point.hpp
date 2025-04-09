/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 07:56:42 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/09 11:52:23 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
    private:
        const Fixed _x;
        const Fixed _y;

    public:
        Point();
        Point(const float x_value, const float y_value);
        Point(const Point& other);
        Point&  operator=(const Point& other);
        ~Point();

        const Fixed&    getX() const;
        const Fixed&    getY() const;
} ;

bool            bsp(Point const a, Point const b, Point const c, Point const point);
std::ostream&   operator<<(std::ostream& os, const Fixed& fixed);

#endif