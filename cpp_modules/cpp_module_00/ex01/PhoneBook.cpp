/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:53:29 by aflorido          #+#    #+#             */
/*   Updated: 2025/01/19 18:55:20 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static std::string truncateWithDot(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

/**
 * Constructor for PhoneBook class
 */
PhoneBook::PhoneBook()
{
	index = 0;
	contactsCount = 0;
	for (int i = 0; i < MAX_CONTACTS; i++)
		contacts[i] = NULL;
}

/**
 * Destructor for PhoneBook class
 */
PhoneBook::~PhoneBook()
{
	for (int i = 0; i < MAX_CONTACTS && contacts[i] != NULL; i++)
		delete contacts[i];
}

/**
 * Add a contact to the phonebook.
 * The fields of the contact are asked to the user.
 * The contact is added to the contacts array, updating the contacts_count.
 * If the contacts array is full, the new contact will replace the oldest one.
 */
void PhoneBook::addContact()
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	/**
	 * While all fields are required, they are not validated further,
	 * meaning it is possible to have a name that is only whitespace,
	 * or a phone number that is not a number
	*/ 
	std::cout << "Enter the first name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter the last name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter the nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Enter the phone number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter the darkest secret: ";
	std::getline(std::cin, darkestSecret);

	// If any field is empty, the contact is not added
	if (firstName.empty() || lastName.empty() || nickname.empty()
			|| phoneNumber.empty() || darkestSecret.empty())
	{
		std::cout << RED "All fields are required" RESET << std::endl;
		return;
	}

	Contact *contact = new Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	if (contactsCount == MAX_CONTACTS)
		delete contacts[index];
	contacts[index] = contact;
	index = (index + 1) % MAX_CONTACTS;
	if (contactsCount < MAX_CONTACTS)
		contactsCount++;
}

/**
 * Print the contacts in the phonebook.
 * The user is asked to enter the index of the contact to display.
 * If the index is not valid, the user is informed.
 */
void PhoneBook::searchContact()
{
	if (contactsCount == 0)
	{
		std::cout << YELLOW "No contacts in the phonebook" RESET << std::endl;
		return;
	}

	std::cout << BOLD "     index|first name| last name|  nickname" RESET << std::endl;
	for (int i = 0; i < contactsCount; i++)
	{
		std::cout << std::setw(10) << (i + 1) << "|"
				  << std::setw(10) << truncateWithDot(contacts[i]->getFirstName()) << "|"
				  << std::setw(10) << truncateWithDot(contacts[i]->getLastName()) << "|"
				  << std::setw(10) << truncateWithDot(contacts[i]->getNickname())
				  << std::endl;
	}

	std::string index_str;
	std::cout << "Enter the index of the contact: ";
	std::getline(std::cin, index_str);
	int index = std::atoi(index_str.c_str()) - 1;
	if (index < 0 || index >= contactsCount)
	{
		std::cout << RED "Invalid index" RESET << std::endl;
		return;
	}

	Contact *contact = contacts[index];
	std::cout << "First name: " << contact->getFirstName()
			  << "\nLast name: " << contact->getLastName()
			  << "\nNickname: " << contact->getNickname()
			  << "\nPhone number: " << contact->getPhoneNumber()
			  << std::endl;
}
