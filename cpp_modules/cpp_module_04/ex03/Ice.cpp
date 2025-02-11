/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:38:49 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/09 21:22:45 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria()
{
	std::cout << "Ice Materia instance created." << std::endl;
	_type = "ice";
}

Ice::Ice(const Ice &other) : AMateria()
{
	(void)other;
	std::cout << "Ice Materia instance created as a copy." << std::endl;
	_type = "ice";
}

Ice::~Ice()
{
	std::cout << "Ice Materia instance destroyed." << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	std::cout << "Asignment operator for Ice Materia called." << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

Ice *Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
