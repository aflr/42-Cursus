/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:02:16 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/09 00:21:05 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

#include <iostream>

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure &other);
	~Cure();
	Cure &operator=(const Cure &other);

	Cure *clone() const;
	void use(ICharacter &target);
};

#endif
