/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:27:55 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/08 23:33:32 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

#include <iostream>

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(std::string type);
	~WrongCat();
	WrongCat &operator=(const WrongCat &other);

	void makeSound() const;
};

#endif
