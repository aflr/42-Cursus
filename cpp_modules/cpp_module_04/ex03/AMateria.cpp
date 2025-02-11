/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:28:52 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/09 21:45:13 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
{
	std::cout << "Materia instance created with empty type." << std::endl;
	_type = "?";
}

AMateria::AMateria(std::string const &type)
{
	std::cout << "Materia instance created with " << type << " type." << std::endl;
	this->_type = type;
}

AMateria::AMateria(const AMateria &other)
{
	std::cout << "Materia instance created as a copy." << std::endl;
	if (this == &other)
		return;
	this->_type = other._type;
}

AMateria::~AMateria()
{
	std::cout << "Materia instance destroyed." << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	std::cout << "Asignment operator for Materia called." << std::endl;
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

std::string const &AMateria::getType() const
{
	std::string const &typeRef = this->_type;
	return (typeRef);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "Materia used on " << target.getName() << ". Nothing happened." << std::endl;
}
