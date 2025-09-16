#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	std::string	s;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < ac; i++)
		{
			s = std::string(av[i]);
			for (int j = 0; j < (int)s.length(); j++)
				s[j] = std::toupper(s[j]);
			std::cout << s;
			// if (i < ac - 1 && (int)s.length() != 0)
			// 	std::cout << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}