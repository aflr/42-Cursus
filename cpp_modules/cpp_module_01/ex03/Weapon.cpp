/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:27:22 by aflorido          #+#    #+#             */
/*   Updated: 2025/01/14 16:31:34 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {}

Weapon::~Weapon() {}

const std::string &Weapon::getType(void) const
{
	return (this->type);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}
