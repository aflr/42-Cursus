/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:58:50 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/08 13:35:30 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain instance created." << std::endl;
	// Initialize all ideas to empty strings
	for (int i = 0; i < MAX_IDEAS; i++)
		ideas[i] = "";
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain instance created as a copy." << std::endl;
	if (this == &other)
		return;
	int i = 0;
	while (i < MAX_IDEAS)
	{
		this->ideas[i] = other.ideas[i];
		i++;
	}
}

Brain::~Brain()
{
	std::cout << "Brain instance destroyed." << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Asignment operator for Brain called" << std::endl;
	if (this == &other)
		return (*this);
	int i = 0;
	while (i < MAX_IDEAS)
	{
		this->ideas[i] = other.ideas[i];
		i++;
	}
	return (*this);
}

void Brain::addIdea(std::string idea)
{
	int i = 0;
	while (i < MAX_IDEAS && ideas[i] != "")
		i++;
	if (i == MAX_IDEAS)
	{
		std::cout << "Brain is full of ideas." << std::endl;
		return ;
	}
	ideas[i] = idea;
}

std::string Brain::getIdea(int idx) const
{
	if (idx < 0 || idx >= MAX_IDEAS)
		return ("");
	return (ideas[idx]);
}

void Brain::removeIdea(int idx)
{
	if (idx < 0 || idx >= MAX_IDEAS)
		return;
	ideas[idx] = "";
}
