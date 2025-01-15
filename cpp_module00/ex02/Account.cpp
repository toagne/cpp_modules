/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:07:14 by mpellegr          #+#    #+#             */
/*   Updated: 2025/01/15 12:36:34 by mpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	std::cout << "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created" << std::endl;
}

Account::~Account( void ) {
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int Account::getNbAccounts( void ) { return _nbAccounts; }
int Account::getTotalAmount( void ) { return _totalAmount; }
int Account::getNbDeposits( void ) { return _totalNbDeposits; }
int Account::getNbWithdrawals( void ) { return _totalNbWithdrawals; }

void Account::displayAccountsInfos( void ) {
	std::cout << "accounts:" << _nbAccounts
			  << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit( int deposit) {
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << (_amount - deposit)
			  << ";deposit;" << deposit
			  << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal ) {
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount
			  << ";withdrawal:";
	if (withdrawal > _amount) {
		std::cout << "refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	std::cout << withdrawal
			  << ";amount:" << _amount
			  << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int Account::checkAmount( void ) const { return _amount; }

void Account::displayStatus( void ) const {
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals << std::endl;
}