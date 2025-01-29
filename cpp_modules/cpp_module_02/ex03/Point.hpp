/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:32:40 by aflorido          #+#    #+#             */
/*   Updated: 2025/01/26 21:11:03 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

#include <iostream>
#include <string>
#include <ostream>

class Point
{
private:
	Fixed const x;
	Fixed const y;

public:
	Point();
	Point(const float x, const float y);
	Point(const Fixed x, const Fixed y);
	Point(const Point &other);
	~Point();

	Point &operator=(const Point &other);

	Fixed getX(void) const;
	Fixed getY(void) const;
};

std::ostream &operator<<(std::ostream &os, const Point &point);

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
