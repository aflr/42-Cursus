/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:59:40 by aflorido          #+#    #+#             */
/*   Updated: 2025/01/12 16:45:44 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define NOARG "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << NOARG;
	for (int i = 1; i < argc; i++)
		for (int j = 0; argv[i][j] != '\0'; j++)
			std::cout << (char)toupper(argv[i][j]);
	std::cout << std::endl;
	return (0);
}
