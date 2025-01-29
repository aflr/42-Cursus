/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:27:27 by aflorido          #+#    #+#             */
/*   Updated: 2025/01/14 16:28:00 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
public:
	Weapon(std::string type);
	~Weapon();
	const std::string &getType(void) const;
	void setType(std::string type);

private:
	std::string type;
};

#endif