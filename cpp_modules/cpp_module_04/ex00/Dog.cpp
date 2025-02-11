/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:29:40 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/09 00:04:05 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog instance created." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog instance created as a copy." << std::endl;
	type = other.type;
}

Dog::~Dog()
{
	std::cout << "Dog instance destroyed." << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Asignment operator for Dog called." << std::endl;
	if (this == &other)
		return (*this);
	type = other.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "The " << type << " barks." << std::endl;
}
