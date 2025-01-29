/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:04:30 by aflorido          #+#    #+#             */
/*   Updated: 2025/01/14 16:01:23 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string name;

public:
	Zombie();
	Zombie(std::string name);
	Zombie(Zombie const &other);
	~Zombie();
	void setName(std::string name);
	void announce(void);
};

Zombie *zombieHorde(int N, std::string name);

#endif