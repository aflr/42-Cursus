/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:36:09 by aflorido          #+#    #+#             */
/*   Updated: 2025/01/26 17:29:42 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <ostream>
#include <cmath>
#include <stdexcept>

class Fixed
{
	private:
		int value;
		static const int FRAC_BITS;
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &other);
		~Fixed();

		/* Assignment operator */
		Fixed &operator=(const Fixed &other);

		/* Comparison operators */
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		/* Arithmetic operators */
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		/* Prefix increment and decrement operators */
		Fixed &operator++(void);
		Fixed &operator--(void);

		/* Postfix increment and decrement operators */
		Fixed operator++(int);
		Fixed operator--(int);

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;

		/* Min static functions */
		static Fixed &min(Fixed &a, Fixed &b);
		const static Fixed &min(const Fixed &a, const Fixed &b);

		/* Max static functions */
		static Fixed &max(Fixed &a, Fixed &b);
		const static Fixed &max(const Fixed &a, const Fixed &b);
};

// Extraction operator
std::ostream &operator <<(std::ostream &os, const Fixed &fixed);

#endif
