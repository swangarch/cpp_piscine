#include <iostream>
#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

int	main(int ac, char **av)
{
	(void)av;
	if (ac > 1)
	{
		std::cerr << RED << "Error: No argument is required" << COLOR_END << std::endl;
		return (1);
	}

	PhoneBook phonebook;
	return (0);
}