/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 07:56:45 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/11 09:05:17 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Calculate area of triangle using 2D determinant formula:
//              
//              Area = 1/2 det|A|
//
//  determinant : [ x1     y1      1 ]
//  in matrix   : [ x2     y2      1 ]
//              : [ x3     y3      1 ]
//
// expanded into:
// Determinant  = (+) x1(y2*1 - y3*1) (-) y1(x2*1 - x3*1) (+) 1(x2*y3 - x3*y2)
//              = x1y2 - x2y3 - x2y1 + x3y1 + x2y3 - x3y2
//              = x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)
//
// Area = 1/2 | x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2) |
Fixed   area(Point const a, Point const b, Point const c) {
    Fixed area = (((a.getX() * (b.getY() - c.getY())) + 
                   (b.getX() * (c.getY() - a.getY())) + 
                   (c.getX() * (a.getY() - b.getY()))) / Fixed(2));

    if (area < 0) { return (area * -1); }
    else { return (area); }
}

// if the point is on a vertex/edge, area will be 0
// if total area = a1 + a2 + a3, return (true)
// else, return (false)
//
// epsilon : small threshold value used to handle floating-point comparison inaccuracies
// in the case where the difference between total area and sum is less than epsilon it is considered of equal value
//
// Floating-point numbers can't always represent exact values due to how they're stored in binary
//      float x = 0.1f + 0.2f;  (Equals 0.300000012...)
//      if (x == 0.3f)          (This might be false)
bool    bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed total = area(a, b, c);
    Fixed a1 = area(a, b, point);
    Fixed a2 = area(b, c, point);
    Fixed a3 = area(c, a, point);

    if (a1 == Fixed(0) || a2 == Fixed (0) || a3 == Fixed(0))
        return (false);

    Fixed sum = a1 + a2 + a3;
    Fixed diff = sum > total ? sum - total : total - sum;
    Fixed epsilon(0.01f);
    
    return (diff < epsilon);
}
