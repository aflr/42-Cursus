/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:53:43 by aflorido          #+#    #+#             */
/*   Updated: 2025/01/19 18:03:55 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "ft_std.h"
# include "Contact.hpp"
# include "colors.h"

# define MAX_CONTACTS 8

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void	addContact();
		void	searchContact();
	private:
		int			index;			// Current index to add a new contact
		int			contactsCount;	// Number of contacts in the phonebook
		Contact		*contacts[MAX_CONTACTS];	// Array of contacts
};

#endif
