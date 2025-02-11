/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:29:40 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/09 00:05:46 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("?")
{
	std::cout << "Animal instance created with empty type." << std::endl;
}

Animal::Animal(const std::string type) : type(type)
{
	std::cout << "Animal instance created with type " << this->type << "." << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal instance created as a copy." << std::endl;
	if (this == &other)
		return;
	this->type = other.type;
}

Animal::~Animal()
{
	std::cout << "Animal instance destroyed." << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Asignment operator for Animal called" << std::endl;
	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

std::string const &Animal::getType() const
{
	std::string const &typeRef = this->type;
	return (typeRef);
}

void Animal::setType(std::string type)
{
	this->type = type;
}

void Animal::makeSound() const
{
	std::cout << "The " << this->type << " makes a cursed sound." << std::endl;
}
