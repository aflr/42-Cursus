/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:05:02 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/09 21:22:29 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria()
{
	std::cout << "Cure Materia instance created." << std::endl;
	_type = "cure";
}

Cure::Cure(const Cure &other) : AMateria()
{
	(void)other;
	std::cout << "Cure Materia instance created as a copy." << std::endl;
	_type = "cure";
}

Cure::~Cure()
{
	std::cout << "Cure Materia instance destroyed." << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
	std::cout << "Asignment operator for Cure Materia called." << std::endl;
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

Cure *Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
