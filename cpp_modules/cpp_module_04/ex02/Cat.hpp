/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:27:55 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/08 23:28:54 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

#include <iostream>

class Cat : public AAnimal
{
public:
	Cat();
	Cat(const Cat &other);
	~Cat();
	Cat &operator=(const Cat &other);

	void makeSound() const;
	Brain &getBrain() const;

private:
	Brain *_brain;
};

#endif