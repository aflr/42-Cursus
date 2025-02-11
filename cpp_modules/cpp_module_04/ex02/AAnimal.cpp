/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:29:40 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/09 00:07:03 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	this->type = "?";
	std::cout << "Animal instance created with empty type." << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "Animal instance created as a copy." << std::endl;
	if (this == &other)
		return;
	this->type = other.type;
}

AAnimal::~AAnimal()
{
	std::cout << "Animal instance destroyed." << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	std::cout << "Asignment operator for Animal called." << std::endl;
	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

std::string const &AAnimal::getType() const
{
	std::string const &typeRef = this->type;
	return (typeRef);
}

void AAnimal::setType(std::string type)
{
	this->type = type;
}

void AAnimal::makeSound() const
{
	std::cout << "The " << type << " makes a cursed sound." << std::endl;
}
