/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:29:40 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/08 13:40:11 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
	std::cout << "Dog instance created." << std::endl;
	type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog &other) : AAnimal(other)
{
	std::cout << "Dog instance created as a copy." << std::endl;
	if (this == &other)
		return;
	type = other.type;
	_brain = new Brain(*other._brain);
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog instance destroyed." << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Asignment operator for Dog called." << std::endl;
	if (this == &other)
		return (*this);
	type = other.type;
	delete _brain;
	_brain = new Brain(*other._brain);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "The " << type << " barks." << std::endl;
}

Brain &Dog::getBrain() const
{
	return (*_brain);
}
