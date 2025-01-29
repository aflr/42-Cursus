/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:36:01 by aflorido          #+#    #+#             */
/*   Updated: 2025/01/25 22:22:28 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::FRAC_BITS = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;

	this->value = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;

	this->value = value << Fixed::FRAC_BITS;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;

	this->value = roundf(value * (1 << Fixed::FRAC_BITS));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;

	*this = other;
}

Fixed &Fixed::operator =(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this == &other) {
		return (*this);
	}
	// The line below is the same as this->value = other.getRawBits();
	// The reason this is done differently here (ex01) and in ex00
	// is to match the expected outputs given in the subject.
	this->value = other.value;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;

	this->value = 0;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;

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

std::ostream &operator <<(std::ostream &stream, const Fixed &fixed)
{
	return (stream << fixed.toFloat());
}
