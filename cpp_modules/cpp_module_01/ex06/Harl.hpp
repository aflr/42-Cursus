/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:07:03 by aflorido          #+#    #+#             */
/*   Updated: 2025/01/22 11:54:11 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

#define MAX_LEVELS 4

class Harl
{
public:
	Harl();
	~Harl();
	void complain(std::string level);

private:
	static const std::string LEVELS[MAX_LEVELS];
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

#endif
