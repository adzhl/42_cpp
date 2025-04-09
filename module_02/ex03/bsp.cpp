/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 07:56:45 by abinti-a          #+#    #+#             */
/*   Updated: 2025/04/09 18:24:30 by abinti-a         ###   ########.fr       */
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

}

bool    bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed total = area(point, a, b);
}

