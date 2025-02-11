/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:27:55 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/08 23:23:52 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(const std::string type);
	WrongAnimal(const WrongAnimal &other);
	~WrongAnimal(); // notice this is not virtual
	WrongAnimal &operator=(const WrongAnimal &other);

	std::string const &getType() const;
	void setType(std::string type);
	void makeSound() const; // notice this is not virtual

protected:
	std::string type;
};

#endif
