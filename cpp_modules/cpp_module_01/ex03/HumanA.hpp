/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:32:36 by aflorido          #+#    #+#             */
/*   Updated: 2025/01/14 16:33:10 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>

#include "Weapon.hpp"

class HumanA
{
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack(void);

private:
	std::string name;
	Weapon &weapon;
};

#endif