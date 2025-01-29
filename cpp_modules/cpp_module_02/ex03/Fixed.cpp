/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:36:01 by aflorido          #+#    #+#             */
/*   Updated: 2025/01/26 20:23:39 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::FRAC_BITS = 8;

Fixed::Fixed()
{
	this->value = 0;
}

Fixed::Fixed(const int value)
{
	this->value = value << Fixed::FRAC_BITS;
}

Fixed::Fixed(const float value)
{
	this->value = roundf(value * (1 << Fixed::FRAC_BITS));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this == &other)
	{
		return (*this);
	}
	this->value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	this->value = 0;
}

int Fixed::getRawBits(void) const
{
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->value / (1 << Fixed::FRAC_BITS));
}

int Fixed::toInt(void) const
{
	return (this->value >> Fixed::FRAC_BITS);
}

/* Extraction operator */

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	return (os << fixed.toFloat());
}

/* Comparison operators */

bool Fixed::operator>(const Fixed &other) const
{
	return (other < *this);
}

bool Fixed::operator<(const Fixed &other) const
{
	// All other comparison operators are implemented in terms of the < operator
	return (this->value < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
	return !(*this < other);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return !(*this > other);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->value == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const
{
	return !(*this == other);
}

/* Arithmetic operators */

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;

	result.setRawBits(this->value + other.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;

	result.setRawBits(this->value - other.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;

	result.setRawBits((this->value * other.getRawBits()) >> Fixed::FRAC_BITS);
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;

	if (other.getRawBits() == 0)
	{
		throw std::invalid_argument("Division by zero");
	}
	result.setRawBits((this->value << Fixed::FRAC_BITS) / other.getRawBits());
	return (result);
}

/* Prefix increment and decrement operators */

Fixed &Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

/*
	Postfix increment and decrement operators,
	implemented in terms of the prefix versions
*/

Fixed Fixed::operator++(int)
{
	Fixed old = *this;
	operator++();
	return (old);
}

Fixed Fixed::operator--(int)
{
	Fixed old = *this;
	operator--();
	return (old);
}

/* Min static functions */

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

/* Max static functions */

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}
