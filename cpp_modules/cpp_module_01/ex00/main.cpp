/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:25:42 by aflorido          #+#    #+#             */
/*   Updated: 2025/01/14 15:38:56 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	/* --- Zombie in heap --- */
	Zombie *zombie = newZombie("Zombie_1");
	zombie->announce();
	delete zombie;

	/* --- Zombie in stack --- */
	randomChump("Zombie_2");

	/* Zombie in heap can be reused and killed later */
	zombie = newZombie("Zombie_3");
	zombie->announce();

	randomChump("Zombie_4");

	zombie->announce();
	delete zombie;

	return (0);
}
