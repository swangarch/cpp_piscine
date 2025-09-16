#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
	this->_command = "";
	this->_index = 0;

	std::cout << YELLOW << "This is a Awesome PhoneBook." << COLOR_END << std::endl
			  << YELLOW << "ADD: add new contact, SEARCH: show contacts, EXIT: quit." 
			  << COLOR_END << std::endl;

	while (1)
	{
		std::cout << YELLOW << "Please enter your command: " << COLOR_END;
		std::getline(std::cin, this->_command, '\n');
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return ;
		}
		if(this->_command == "ADD")
		{
			if (_Add() == true)
				continue ;
			else
				return ;
		}
		else if (this->_command == "SEARCH")
		{
			if (_Search() == true)
				continue ;
			else
				return ;
		}
		else if (this->_command == "EXIT")
			return ;
		else
			std::cerr << RED << "Error: Wrong command, retype or type EXIT to quit." << COLOR_END << std::endl;
	}
	return;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << RED << "PhoneBook destroyed, you lost all the contacts" << COLOR_END << std::endl;
	return;
}

void PhoneBook::_DisplayContactHeader(void)
{
    std::cout   << YELLOW << "|"
				<< std::setw(10) << std::right << "Index" << "|"
                << std::setw(10) << std::right << "First name" << "|" 
                << std::setw(10) << std::right << "Last name" << "|" 
                << std::setw(10) << std::right << "Nick name" << "|" 
				<< COLOR_END << std::endl;
    return;
}

bool	PhoneBook::_Add(void)
{
	this->_contacts[this->_index % 8].InputContact(this->_index % 8);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		return (false);
	}
	if (!this->_contacts[this->_index % 8].HasError())
		this->_index++;
	return (true);
}

bool	PhoneBook::_Search(void)
{
	std::cout << std::endl;
	_DisplayContactHeader();
	for (int i = 0; i < 45; i++)
	{
		if (i % 11 == 0)
			std::cout << YELLOW << "|" << COLOR_END;
		else
			std::cout << YELLOW << "-" << COLOR_END;
	}
	std::cout << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (!this->_contacts[i % 8].HasError())
			this->_contacts[i % 8].DisplayContactInTable();
	}
	std::cout << std::endl;
	
	if (this->_index == 0)
	{
		std::cout << RED << "Empty phone book." << COLOR_END << std::endl;
		return (true) ;
	}
	std::cout << YELLOW << "Enter index: " << COLOR_END;
	std::getline(std::cin, this->_command, '\n');
	if (std::cin.eof())
	{
		std::cout << std::endl;
		return (false);
	}
	if ((int)this->_command.length() != 1 || !std::isdigit(this->_command[0]) || this->_command[0] > '7' || this->_command[0] - '0' >= this->_index)
	{
		std::cerr << RED << "Error: Wrong index." << COLOR_END << std::endl;
		return (true) ;
	}
	_contacts[this->_command[0] - '0'].DisplayContact();
	return (true) ;
}