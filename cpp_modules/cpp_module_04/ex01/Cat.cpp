/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:29:40 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/09 00:03:48 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat instance created." << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat instance created as a copy." << std::endl;
	if (this == &other)
		return;
	type = other.type;
	_brain = new Brain(*other._brain);
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat instance destroyed." << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Asignment operator for Cat called" << std::endl;
	if (this == &other)
		return (*this);
	type = other.type;
	delete _brain;
	_brain = new Brain(*other._brain);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "The " << type << " meows." << std::endl;
}

Brain &Cat::getBrain() const
{
	return (*_brain);
}
