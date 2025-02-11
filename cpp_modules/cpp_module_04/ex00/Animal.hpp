/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:27:55 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/06 19:28:36 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
public:
	Animal();
	Animal(std::string type);
	Animal(const Animal &other);
	virtual ~Animal();
	Animal &operator=(const Animal &other);

	std::string const &getType() const;
	void setType(std::string type);
	virtual void makeSound() const;

protected:
	std::string type;
};

#endif
