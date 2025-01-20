/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:47:32 by aflorido          #+#    #+#             */
/*   Updated: 2025/01/15 19:56:45 by aflorido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/**
 * Constructor for Account class
 * @attention The number of accounts and the total amount must be updated.
 */
Account::Account( int initial_deposit )
		: _accountIndex( _nbAccounts ), _amount( initial_deposit ),
		_nbDeposits( 0 ), _nbWithdrawals( 0 )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";created"
			<< std::endl;

	_nbAccounts++;
	_totalAmount += initial_deposit;

	return ;
}

/**
 * Default constructor for Account class
 * This is private and never used.
 */
Account::Account(void) {}

/**
 * Destructor for Account class
 * @attention The number of accounts and the total amount must be updated.
 * 
 * Example: [19920104_091532] index:2;amount:957;closed
 */
Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";closed"
			<< std::endl;

	_nbAccounts--;
	_totalAmount -= _amount;

	return ;
}

// Never used
int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

// Never used
int Account::getTotalAmount(void)
{
	return _totalAmount;
}

// Never used
int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

// Never used
int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

/**
 * Displays the total number of accounts, the total amount of all accounts,
 * the total number of deposits and the total number of withdrawals.
 * 
 * Example: [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
 */
void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			<< ";total:" << _totalAmount
			<< ";deposits:" << _totalNbDeposits
			<< ";withdrawals:" << _totalNbWithdrawals
			<< std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";deposit:" << deposit;

	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;

	std::cout << ";amount:" << _amount
			<< ";nb_deposits:" << _nbDeposits
			<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";withdrawal:";

	if (_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return false;
	}

	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	_nbWithdrawals++;

	std::cout << withdrawal
			<< ";amount:" << _amount
			<< ";nb_withdrawals:" << _nbWithdrawals
			<< std::endl;

	return true;
}

/**
 * Probably a getter for the amount in the account.
 * This is never used in the tests.
 */
int Account::checkAmount(void) const
{
	return _amount;
}

/**
 * Displays all the information of the account.
 * 
 * Example: [19920104_091532] index:2;amount:957;deposits:0;withdrawals:0
 */
void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";deposits:" << _nbDeposits
			<< ";withdrawals:" << _nbWithdrawals
			<< std::endl;
}

/**
 * Displays the current timestamp.
 * 
 * Example: [19920104_091532]  // January 4th, 1992, 9:15:32
 */
void Account::_displayTimestamp(void)
{
	time_t	now = time(0);
	tm		*ltm = localtime(&now);

	std::cout << "["
			<< 1900 + ltm->tm_year
			<< std::setw(2) << std::setfill('0') << 1 + ltm->tm_mon
			<< std::setw(2) << std::setfill('0') << ltm->tm_mday
			<< "_"
			<< std::setw(2) << std::setfill('0') << ltm->tm_hour
			<< std::setw(2) << std::setfill('0') << ltm->tm_min
			<< std::setw(2) << std::setfill('0') << ltm->tm_sec
			<< "] ";
}
/**
 struct tm {
	int tm_sec;    // Seconds (0-60) -> 60 to account for leap seconds
	int tm_min;    // Minutes (0-59)
	int tm_hour;   // Hours (0-23)
	int tm_mday;   // Day of the month (1-31)
	int tm_mon;    // Month (0-11)
	int tm_year;   // Year - 1900
	int tm_wday;   // Day of the week (0-6, Sunday = 0)
	int tm_yday;   // Day in the year (0-365, 1 Jan = 0)
	int tm_isdst;  // Daylight saving time
};
*/
