/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:29:40 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/08 23:23:04 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	type = "Wrong Cat";
	std::cout << "Wrong Cat instance created with " << this->type << " type." << std::endl;
}

WrongCat::WrongCat(const std::string type) : WrongAnimal(type)
{
	std::cout << "Wrong Cat instance created with " << this->type << " type." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Wrong Cat instance destroyed." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "Asignment operator for Wrong Cat called." << std::endl;
	if (this == &other)
		return (*this);
	type = other.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "The " << type << " meows." << std::endl;
}
