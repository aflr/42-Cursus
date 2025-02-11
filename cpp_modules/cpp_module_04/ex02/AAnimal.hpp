/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:27:55 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/08 10:18:03 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal
{
public:
	AAnimal();
	AAnimal(const AAnimal &other);
	virtual ~AAnimal();
	AAnimal &operator=(const AAnimal &other);

	std::string const &getType() const;
	void setType(std::string type);
	virtual void makeSound() const = 0; // Pure virtual function

protected:
	std::string type;
};

#endif
