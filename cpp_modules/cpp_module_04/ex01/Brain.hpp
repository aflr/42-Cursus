/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:58:50 by aflorido          #+#    #+#             */
/*   Updated: 2025/02/08 11:36:51 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
public:
	Brain();
	Brain(const Brain &other);
	~Brain();
	Brain &operator=(const Brain &other);

	void addIdea(std::string idea);
	std::string getIdea(int idx) const;
	void removeIdea(int idx);

	static const int MAX_IDEAS = 100;

private:
	std::string ideas[MAX_IDEAS];
};

#endif
