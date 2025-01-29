/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:32:25 by aflorido          #+#    #+#             */
/*   Updated: 2025/01/26 20:49:55 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#define CROSS_PRODUCT(p1, p2, p3) ((p2.getX() - p1.getX()) * (p3.getY() - p1.getY()) - (p2.getY() - p1.getY()) * (p3.getX() - p1.getX()))

/**
 * @brief Check if a point is inside a triangle
 *
 * @param a, b, c The vertices of our beloved triangle
 * @param point The point to check
 * @return true if the point is inside the triangle, false otherwise.
 * 		   If the point is a vertex or on edge, it will return false.
 */
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed const z1 = CROSS_PRODUCT(a, b, point);
	Fixed const z2 = CROSS_PRODUCT(b, c, point);
	Fixed const z3 = CROSS_PRODUCT(c, a, point);

	return ((z1 > 0 && z2 > 0 && z3 > 0)
			|| (z1 < 0 && z2 < 0 && z3 < 0));
}
