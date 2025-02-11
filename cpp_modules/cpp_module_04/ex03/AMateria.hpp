/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:37:56 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/09 00:33:16 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class ICharacter; // Forward declaration

class AMateria
{
protected:
	std::string _type;

public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(const AMateria &other);
	virtual ~AMateria();
	AMateria &operator=(const AMateria &other);

	std::string const &getType() const;
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif
