#include <iostream>
// #include <chrono>
//#include <iomanip>
#include <ctime>
#include "Account.hpp"

Account::Account(void)
{
    ;
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" <<  this->_accountIndex << ";"
			  << "amount:" << checkAmount() << ";"
			  << "created" << std::endl;
	_nbAccounts++;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			  << "amount:" << checkAmount() << ";"
			  << "closed" << std::endl;
    return ;
}

int Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

void Account::_displayTimestamp(void)
{
	std::time_t	now = std::time(0);
	std::tm* local_time = std::localtime(&now);
	std::cout << "[" 
			  << (local_time->tm_year + 1900) 
			  << (local_time->tm_mon + 1)
			  << (local_time->tm_mday)
			  << "_"
			  << local_time->tm_hour
			  << local_time->tm_min
			  << local_time->tm_sec
			  << "] ";
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
			  << "total:" << getTotalAmount() << ";"
			  << "deposits:" << getNbDeposits() << ";"
			  << "withdrawals:" << getNbWithdrawals()
			  << std::endl;
}

void    Account::makeDeposit(int deposit)
{
	_displayTimestamp();

	std::cout << "index:" << this->_accountIndex << ";"
			  << "p_amount:" << checkAmount() << ";";

	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	std::cout 
			  << "deposit:" << deposit << ";"
			  << "amount:" << checkAmount() << ";"
			  << "nb_deposits:" << this->_nbDeposits
			  << std::endl;
	return;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();

	std::cout << "index:" << this->_accountIndex << ";"
			  << "p_amount:" << checkAmount() << ";";

	if (withdrawal <= this->_amount)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;

		std::cout << "withdrawal:" << withdrawal << ";"
			  	  << "amount:" << checkAmount() << ";"
			  	  << "nb_withdrawals:" << this->_nbWithdrawals
				  << std::endl;
		return (true);
	}
	else
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
}

int		Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			  << "amount:" << checkAmount() << ";"
			  << "deposits:" << this->_nbDeposits << ";"
			  << "withdrawals:" << this->_nbWithdrawals
			  << std::endl;
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
