/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:24:49 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/09 21:37:59 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

#include <cstring>
#include <iostream>

int main()
{
	std::cout << "\n TEST FROM SUBJECT \n" << std::endl;
	{
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter *me = new Character("me");

		AMateria *tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter *bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	std::cout << "\n COMPLETE TEST \n" << std::endl;
	{
		MateriaSource *src = new MateriaSource();

		std::cout << std::endl;

		// Materia default and copy constructors
		// These don't need to be deleted because they are added to the MateriaSource
		Ice *ice1 = new Ice();
		Ice *ice2 = new Ice(*ice1);
		Cure *cure1 = new Cure();
		Cure *cure2 = new Cure(*cure1);

		std::cout << std::endl;

		Character hero1("Cloud Strife");
		Character hero2("Aerith Gainsborough");

		// Character copy constructor
		Character hero3 = Character(hero1);

		std::cout << std::endl;

		// Correctly lean 4 materias
		src->learnMateria(ice1);
		src->learnMateria(cure1);
		src->learnMateria(cure2);
		src->learnMateria(ice2);

		// Negative test: too many materias
		Ice ice3 = Ice();
		src->learnMateria(&ice3);

		// Negative test: NULL materia
		src->learnMateria(NULL);

		std::cout << std::endl;

		// Create previously learned materias
		AMateria *createdIce = src->createMateria("ice");
		AMateria *createdCure = src->createMateria("cure");

		// Negative test: unknown materia
		AMateria *fakeMateria = src->createMateria("keystone");

		std::cout << std::endl;

		hero1.equip(createdIce);
		hero1.equip(createdCure);

		// Negative test: equip NULL materia (doesn't do anything)
		hero1.equip(fakeMateria);

		// Unequip a materia
		AMateria *unequippedMateria = hero1.getMateriaAt(1);
		hero1.unequip(1);

		// Negative test: unequip NULL materia
		hero1.unequip(1);

		// Reuse the unequipped materia
		hero2.equip(unequippedMateria);

		std::cout << std::endl;

		// Use the materias
		hero1.use(0, hero2);
		hero2.use(0, hero1);

		// Negative tests: use out of bounds
		hero1.use(-1, hero1);
		hero1.use(42, hero1);

		// Negative test: use NULL materia
		hero1.use(1, hero1);

		std::cout << std::endl;

		delete (src);

		std::cout << std::endl;
	}
	return (0);
}
