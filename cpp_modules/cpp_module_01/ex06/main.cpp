/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:59:11 by aflorido          #+#    #+#             */
/*   Updated: 2025/01/22 12:10:37 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./harlFilter [DEBUG, INFO, WARNING, ERROR]" << std::endl;
		return (1);
	}
	Harl harl;
	harl.complain(av[1]);
	return (0);
}
