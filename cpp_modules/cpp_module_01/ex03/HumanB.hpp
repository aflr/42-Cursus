/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:33:16 by aflorido          #+#    #+#             */
/*   Updated: 2025/01/14 16:34:53 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>

#include "Weapon.hpp"

class HumanB
{
public:
	HumanB(std::string name);
	~HumanB();
	void attack(void);
	void setWeapon(Weapon &weapon);

private:
	std::string name;
	Weapon *weapon;
};

#endif