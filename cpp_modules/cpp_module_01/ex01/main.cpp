/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:56:11 by aflorido          #+#    #+#             */
/*   Updated: 2025/01/14 16:06:23 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *zombies = zombieHorde(5, "Freshmeat");
	for (int i = 0; i < 5; i++)
		zombies[i].announce();
	delete[] zombies;
	return 0;
}
