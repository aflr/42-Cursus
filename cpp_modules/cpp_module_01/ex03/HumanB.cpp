/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:37:32 by aflorido          #+#    #+#             */
/*   Updated: 2025/01/14 16:56:53 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {}

HumanB::~HumanB() {}

void HumanB::attack(void)
{
	std::cout << this->name
			  << (this->weapon ? " attacks with his " + this->weapon->getType() : " has no weapon")
			  << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
