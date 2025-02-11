/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:29:40 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/08 23:21:49 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "?";
	std::cout << "Wrong Animal instance created with empty type." << std::endl;
}

WrongAnimal::WrongAnimal(const std::string type) : type(type)
{
	std::cout << "Wrong Animal instance created with type " << this->type << "." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "Wrong Animal instance created as a copy." << std::endl;
	if (this == &other)
		return;
	type = other.type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal instance destroyed." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "Asignment operator for Wrong Animal called." << std::endl;
	if (this == &other)
		return (*this);
	type = other.type;
	return (*this);
}

std::string const &WrongAnimal::getType() const
{
	std::string const &typeRef = type;
	return (typeRef);
}

void WrongAnimal::setType(std::string type)
{
	this->type = type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "The " << type << " makes an uncanny sound." << std::endl;
}
