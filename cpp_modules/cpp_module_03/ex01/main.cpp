/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:29:18 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/01 23:53:21 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap st("ScavTrap");

	st.attack("Skag");
	st.guardGate();
	st.guardGate();

	return (0);
}

/*
ClapTrap Constructor called for ScavTrap
ScavTrap Constructor called for ScavTrap
ScavTrap ScavTrap attacks Skag, causing 20 points of damage!
ScavTrap is now in Gate keeper mode!
ScavTrap ScavTrap is not able to enter Gate keeper mode!
ScavTrap Destructor called
ClapTrap Destructor called
*/
