/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:09:05 by aflorido          #+#    #+#             */
/*   Updated: 2025/01/14 16:18:16 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN"; // A string variable

	std::string *stringPTR = &str; // A pointer to the string
	std::string &stringREF = str;  // A reference to the string

	std::cout << "The memory address of the string variable: " << &str << std::endl;
	std::cout << "The memory address held by stringPTR:      " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF:      " << &stringREF << std::endl;

	std::cout << "The value of the string variable:  " << str << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
	return (0);
}
