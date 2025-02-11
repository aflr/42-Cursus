/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:33:19 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/09 21:43:59 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : _name("")
{
	std::cout << "Character instance created with no name." << std::endl;
	std::memset(_inventory, 0, MAX_INV_SLOTS * sizeof(AMateria *)); // Set all inventory slots to NULL
}

Character::Character(std::string const &name) : _name(name)
{
	std::cout << "Character " << name << " instance created." << std::endl;
	std::memset(_inventory, 0, MAX_INV_SLOTS * sizeof(AMateria *)); // Set all inventory slots to NULL
}

Character::Character(const Character &other)
{
	std::cout << "Character instance created as a copy." << std::endl;
	if (this == &other)
		return;
	this->_name = other._name;
	for (int i = 0; i < MAX_INV_SLOTS; i++)
		this->_inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : NULL;
}

Character::~Character()
{
	for (int i = 0; i < MAX_INV_SLOTS; i++)
		if (_inventory[i] != NULL)
			delete (_inventory[i]);
	std::cout << "Character instance destroyed." << std::endl;
}

Character &Character::operator=(const Character &other)
{
	std::cout << "Asignment operator for Character called." << std::endl;
	if (this == &other)
		return (*this);
	this->_name = other._name;
	for (int i = 0; i < MAX_INV_SLOTS; i++) {
		if (this->_inventory[i] != NULL)
			delete (this->_inventory[i]);
		this->_inventory[i] = other._inventory[i]->clone();
	}
	return (*this);
}

std::string const &Character::getName() const
{
	std::string const &typeRef = _name;
	return (typeRef);
}

void Character::equip(AMateria *m)
{
	if (m == NULL)
		return;
	for (int i = 0; i < MAX_INV_SLOTS; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cout << _name << " equipped " << m->getType() << " Materia in inventory slot " << i << "." << std::endl;
			return;
		}
	}
	std::cout << "Unable to equip: " << _name << "'s inventory is already full of materias." << std::endl;
}

/**
 * @brief Unequips a materia from the inventory.
 * 
 * This function does not delete the materia, it just removes it from the inventory.
 * `getMateriaAt()` can be used to get the materia before calling this function,
 * to allow for further use or deletion.
 */
void Character::unequip(int idx)
{
	if (idx < 0 || idx >= MAX_INV_SLOTS)
	{
		std::cout << "Unable to unequip: Invalid inventory slot." << std::endl;
		return;
	}
	if (_inventory[idx] == NULL)
	{
		std::cout << "Unable to unequip: " << _name << "'s inventory has no materia in that slot." << std::endl;
		return;
	}
	std::cout << _name << " unequipped " << _inventory[idx]->getType() << " Materia from inventory slot " << idx << "." << std::endl;
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= MAX_INV_SLOTS)
	{
		std::cout << "Unable to use: Invalid inventory slot." << std::endl;
		return;
	}
	if (_inventory[idx] == NULL)
	{
		std::cout << "Unable to use: " << _name << "'s inventory has no materia in slot " << idx << "." << std::endl;
		return;
	}
	_inventory[idx]->use(target);
}

AMateria *Character::getMateriaAt(int idx)
{
	if (idx >= 0 && idx < MAX_INV_SLOTS)
		return (_inventory[idx]);
	return (NULL);
}
