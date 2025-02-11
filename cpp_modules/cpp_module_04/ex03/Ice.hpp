/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:22:03 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/09 00:12:29 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

#include <iostream>

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice &other);
	~Ice();
	Ice &operator=(const Ice &other);

	Ice *clone() const;
	void use(ICharacter &target);
};

#endif
