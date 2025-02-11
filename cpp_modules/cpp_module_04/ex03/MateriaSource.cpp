/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:49:36 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/09 21:08:35 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "Materia Source instance created." << std::endl;
	std::memset(_knownMaterias, 0, MAX_KNOWN_MATERIAS * sizeof(AMateria *));
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "Materia Source instance created as a copy." << std::endl;
	if (this == &other)
		return;
	for (int i = 0; i < MAX_KNOWN_MATERIAS; i++)
		this->_knownMaterias[i] = other._knownMaterias[i];
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAX_KNOWN_MATERIAS; i++)
		if (_knownMaterias[i] != NULL)
			delete (_knownMaterias[i]);
	std::cout << "Materia Source instance destroyed." << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "Asignment operator for Materia Source called." << std::endl;
	if (this == &other)
		return (*this);
	for (int i = 0; i < MAX_KNOWN_MATERIAS; i++)
		this->_knownMaterias[i] = other._knownMaterias[i];
	return (*this);
}

void MateriaSource::learnMateria(AMateria *materia)
{
	if (materia == NULL)
	{
		std::cout << "Unable to learn: Invalid Materia instance." << std::endl;
		return;
	}
	for (int i = 0; i < MAX_KNOWN_MATERIAS; i++)
	{
		if (_knownMaterias[i] == NULL) {
			_knownMaterias[i] = materia;
			std::cout << "Materia learnt into slot " << i << "." << std::endl;
			return;
		}
	}
	std::cout << "Unable to learn: This source is already full of materias." << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < MAX_KNOWN_MATERIAS; i++)
		if (_knownMaterias[i] != NULL && _knownMaterias[i]->getType() == type)
			return (_knownMaterias[i]->clone());
	return (NULL);
}
