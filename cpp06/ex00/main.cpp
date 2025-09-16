#include <iostream>
#include <string>
#include <sstream>
#include "ScalarConverter.hpp"

# ifndef COLOR
# define COLOR

const std::string RED = "\001\033[31m\002";
const std::string YELLOW = "\001\033[33m\002";
const std::string COLOR_END = "\001\033[0m\002";

# endif

int main(int ac, char **av)
{
    std::cout << YELLOW << "Input: " << "(empty)" << COLOR_END << std::endl;
    ScalarConverter::convert("");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    std::cout << YELLOW << "Input: " << "1a" << COLOR_END << std::endl;
    ScalarConverter::convert("1a");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    std::cout << YELLOW << "Input: " << "a" << COLOR_END << std::endl;
    ScalarConverter::convert("a");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    std::cout << YELLOW << "Input: " << "+87" << COLOR_END << std::endl;
    ScalarConverter::convert("+87");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    std::cout << YELLOW << "Input: " << "++112" << COLOR_END << std::endl;
    ScalarConverter::convert("++112");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    std::cout << YELLOW << "Input: " << "-87" << COLOR_END << std::endl;
    ScalarConverter::convert("-87");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    std::cout << YELLOW << "Input: " << "--112" << COLOR_END << std::endl;
    ScalarConverter::convert("--112");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    std::cout << YELLOW << "Input: " << "2147483647" << COLOR_END << std::endl;
    ScalarConverter::convert("2147483647");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    std::cout << YELLOW << "Input: " << "-2147483648" << COLOR_END << std::endl;
    ScalarConverter::convert("-2147483648");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    std::cout << YELLOW << "Input: " << "2147483648" << COLOR_END << std::endl;
    ScalarConverter::convert("2147483648");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    std::cout << YELLOW << "Input: " << "+112.12312" << COLOR_END << std::endl;
    ScalarConverter::convert("+112.12312");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    std::cout << YELLOW << "Input: " << "+112.0" << COLOR_END << std::endl;
    ScalarConverter::convert("+112.0");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    std::cout << YELLOW << "Input: " << "+112.12312f" << COLOR_END << std::endl;
    ScalarConverter::convert("+112.12312f");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    std::cout << YELLOW << "Input: " << "0" << COLOR_END << std::endl;
    ScalarConverter::convert("0");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    std::cout << YELLOW << "Input: " << "127" << COLOR_END << std::endl;
    ScalarConverter::convert("127");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    std::cout << YELLOW << "Input: " << "7" << COLOR_END << std::endl;
    ScalarConverter::convert("7");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    std::cout << YELLOW << "Input: " << "nanf" << COLOR_END << std::endl;
    ScalarConverter::convert("nanf");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    std::cout << YELLOW << "Input: " << "nan" << COLOR_END << std::endl;
    ScalarConverter::convert("nan");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    std::cout << YELLOW << "Input: " << "+inff" << COLOR_END << std::endl;
    ScalarConverter::convert("+inff");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    std::cout << YELLOW << "Input: " << "-inf" << COLOR_END << std::endl;
    ScalarConverter::convert("-inf");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    std::cout << YELLOW << "Input: " << "-" << COLOR_END << std::endl;
    ScalarConverter::convert("-");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    std::cout << YELLOW << "Input: " << "+" << COLOR_END << std::endl;
    ScalarConverter::convert("+");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    std::cout << YELLOW << "Input: " << "(space)" << COLOR_END << std::endl;
    ScalarConverter::convert(" ");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    std::cout << YELLOW << "Input: " << "c" << COLOR_END << std::endl;
    ScalarConverter::convert("c");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    std::cout << YELLOW << "Input: " << "E" << COLOR_END << std::endl;
    ScalarConverter::convert("E");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    std::cout << YELLOW << "Input: " << "ABAC" << COLOR_END << std::endl;
    ScalarConverter::convert("ABAC");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    std::cout << YELLOW << "Input: " << "1111111111111111111111111111111111111111111111111111111" << COLOR_END << std::endl;
    ScalarConverter::convert("1111111111111111111111111111111111111111111111111111111");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    std::cout << YELLOW << "Input: " << "-1111111111111111111111111111111111111111111111111111111" << COLOR_END << std::endl;
    ScalarConverter::convert("-1111111111111111111111111111111111111111111111111111111");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    std::cout << YELLOW << "Input: " << "-1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111.0" << COLOR_END << std::endl;
    ScalarConverter::convert("-1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111.0");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    std::cout << YELLOW << "Input: " << "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111.0f" << COLOR_END << std::endl;
    ScalarConverter::convert("1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111.0f");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    std::cout << YELLOW << "Input: " << "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111" << COLOR_END << std::endl;
    ScalarConverter::convert("1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");
    std::cout << YELLOW << "__________________________" << COLOR_END << std::endl;

    if (ac == 2)
    {
        std::string input(av[1]);
        ScalarConverter::convert(input);
    }

    return (0);
}