/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:05:49 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/09 20:58:00 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

#include <cstring>
#include <iostream>
#include <stdint.h>

#ifndef MAX_INV_SLOTS
#define MAX_INV_SLOTS 4
#endif

class AMateria; // Forward declaration

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria *_inventory[MAX_INV_SLOTS];

public:
	Character();
	Character(std::string const &name);
	Character(const Character &other);
	~Character();
	Character &operator=(const Character &other);

	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
	AMateria *getMateriaAt(int idx); // Helps avoid leaking unequiped materias
};

#endif
