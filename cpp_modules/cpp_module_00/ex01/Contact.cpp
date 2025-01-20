/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:55:27 by aflorido          #+#    #+#             */
/*   Updated: 2025/01/14 12:16:24 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/**
 * Constructor for Contact class
 */
Contact::Contact(std::string firstName, std::string lastName,
				std::string nickname, std::string phoneNumber,
				std::string darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickname = nickname;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

/**
 * Destructor for Contact class
 */
Contact::~Contact() {}

/**
 * Get the first name of the contact
 * @return the first name of the contact
 */
std::string Contact::getFirstName()
{
	return (this->firstName);
}

/**
 * Get the last name of the contact
 * @return the last name of the contact
 */
std::string Contact::getLastName()
{
	return (this->lastName);
}

/**
 * Get the nickname of the contact
 * @return the nickname of the contact
 */
std::string Contact::getNickname()
{
	return (this->nickname);
}

/**
 * Get the phone number of the contact
 * @return the phone number of the contact
 */
std::string Contact::getPhoneNumber()
{
	return (this->phoneNumber);
}
