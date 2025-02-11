/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:36:20 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/09 20:47:20 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

#include <cstring>
#include <iostream>
#include <stdint.h>
#include <string>

#ifndef MAX_KNOWN_MATERIAS
#define MAX_KNOWN_MATERIAS 4
#endif

class MateriaSource : public IMateriaSource
{
private:
	AMateria *_knownMaterias[MAX_KNOWN_MATERIAS];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	~MateriaSource();
	MateriaSource &operator=(const MateriaSource &other);

	void learnMateria(AMateria *materia);
	AMateria *createMateria(std::string const &type);
};

#endif
