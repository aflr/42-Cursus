/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:52:41 by aflorido          #+#    #+#             */
/*   Updated: 2025/01/14 16:01:48 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * Allocate N Zombie objects in a single allocation.
 * Then, initialize the zombies, giving each one of them the name passed as parameter.
 * The function returns a pointer to the first zombie.
 */
Zombie *zombieHorde(int N, std::string name)
{
	Zombie *zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombies[i].setName(name);
	return zombies;
}
