/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 08:16:17 by abinti-a          #+#    #+#             */
/*   Updated: 2025/03/19 11:25:39 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

// static variables initialization
int Account::_nbAccounts(0);
int Account::_totalAmount(0);
int Account::_totalNbDeposits(0);
int Account::_totalNbWithdrawals(0);


// std::time(NULL) gets the current time in seconds since January 1, 1970 (Unix Epoch).
// std::localtime(&now) converts now to a human-readable tm struct, which stores:
//     tm_year → Years since 1900
//     tm_mon → Months since January (0-11)
//     tm_mday → Day of the month (1-31)
//     tm_hour → Hours (0-23)
//     tm_min → Minutes (0-59)
//     tm_sec → Seconds (0-59)
// strftime() (String Format Time): formats a struct tm date/time into a human-readable string.
void    Account::_displayTimestamp()
{
    std::time_t now = std::time(NULL);
    struct tm *local_time = std::localtime(&now);

    char buffer[20];
    strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", local_time);
    std::cout << buffer;
}

// Constructor
Account::Account(int initial_deposit) : _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    _totalAmount += _amount;
    
    _displayTimestamp();
    std::cout   << "index:" << _accountIndex
                << ";amount:" << _amount 
                << ";created\n";
}

// Destructor
Account::~Account()
{
    _displayTimestamp();
    std::cout   << "index:" << _accountIndex
                << ";amount:" << _amount 
                << ";closed\n";
}

// Display all accounts summary
void    Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout   << "accounts:" << _nbAccounts
                << ";total:" << _totalAmount
                << ";deposits:" << _totalNbDeposits
                << ";withdrawals:" << _totalNbWithdrawals
                << "\n";
}

void    Account::displayStatus() const
{
    _displayTimestamp();
    std::cout   << "index:" << _accountIndex
                << ";amount:" << _amount
                << ";deposits:" << _nbDeposits
                << ";withdrawals:" << _nbWithdrawals
                << "\n";
}

void    Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout   << "index:" << _accountIndex
                << ";p_amount:" << _amount
                << ";deposit:" << deposit;

    _amount += deposit;
    _nbDeposits++;

    std::cout   << ";amount:" << _amount
                << ";nb_deposits:" << _nbDeposits
                << "\n";

    _totalAmount += deposit;
    _totalNbDeposits++;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout   << "index:" << _accountIndex
                << ";p_amount:" << _amount;

    if (_amount < withdrawal)
    {
        std::cout << ";withdrawal:refused\n";
        return (false);
    }
    _amount -= withdrawal;
    _nbWithdrawals++;

    std::cout   << ";withdrawal:" << withdrawal
                << ";amount:" << _amount
                << ";nb_withdrawals:" << _nbWithdrawals
                << "\n";
    
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    return (true);
}