/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:04:30 by aflorido          #+#    #+#             */
/*   Updated: 2025/01/14 15:21:29 by aflorido         ###   ########.fr       */
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
	void announce(void);
};

/**
 * It creates a zombie, name it, and return it so you can use it outside of the function scope.
 */
Zombie *newZombie(std::string name);

/**
 * It creates a zombie, name it, and the zombie announces itself.
 */
void randomChump(std::string name);

/*
- Because in randomChump the zombie dies right away, we can use the stack.
	The zombie will be destroyed when the function ends.
- But in newZombie, we need to return the zombie, so we must use the heap
	and let the caller be responsible for deleting the zombie.
*/
#endif