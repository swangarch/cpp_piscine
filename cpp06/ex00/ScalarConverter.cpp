#include    "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{

}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return (*this);
}

ScalarConverter::~ScalarConverter(void)
{

}

bool    is_char(const std::string& input)
{
    if (input.size() == 1 && (input[0] > '9' || input[0] < '0'))
    {
        return (true);
    }
    return (false);
}

bool    is_digits(const std::string& input)
{
    size_t i = 0;
    if (input[i] == '+' || input[i] == '-')
        i++;

    for (; i < input.size(); i++)
        if (input[i] > '9' || input[i] < '0')
            return (false);
    
    return (true);
}

bool    noIntOverflow(const std::string& input)
{
    std::stringstream ss(input);
    int IntInput;

    ss << input;
    ss >> IntInput;
    if (ss.fail())
        return (false);
    return (true);
}

bool    is_int(const std::string& input)
{
    if (is_digits(input) && noIntOverflow(input))
        return (true);
    return (false);
}

bool    is_double(const std::string& input)
{
    int deciPt = 0;
    int digiAfterDeciPt = 0;

    if (input.size() < 3)  //shortest float is 0.0f
        return (false);

    size_t i = 0;
    if (input[i] == '+' || input[i] == '-')
        i++;

    for (; i < input.size(); i++)
    {
        if (input[i] > '9' || input[i] < '0')
        {
            if (input[i] != '.') //invalid char
                return (false);
            else if (input[i] == '.' && deciPt == 1)  //more than one decimal point
                return (false);
            else if (input[i] == '.')
                deciPt = 1;
        }
        if (deciPt == 1 && (input[i] >= '0' && input[i] <= '9'))
            digiAfterDeciPt++;
    }
    if (digiAfterDeciPt == 0) //no digits after decimal point
        return (false);

    return (true);
}

bool    is_float(const std::string& input)
{
    int deciPt = 0;
    int digiAfterDeciPt = 0;

    if (input.size() < 4)  //shortest float is 0.0f
        return (false);

    if (input[input.size() - 1] != 'f')  //last char is not f
        return (false);

    size_t i = 0;
    if (input[i] == '+' || input[i] == '-')
        i++;

    for (; i < input.size(); i++)
    {
        if (input[i] > '9' || input[i] < '0')
        {
            if (input[i] != '.'  && input[i] != 'f')  //invalid char
                return (false);
            else if (input[i] == '.' && deciPt == 1)  //more than one decimal point
                return (false);
            else if (input[i] == 'f' && i != input.size() - 1)  //f not in the end
                return (false);
            else if (input[i] == '.')
                deciPt = 1;
        }
        if (deciPt == 1 && (input[i] >= '0' && input[i] <= '9'))
            digiAfterDeciPt++;
    }
    if (digiAfterDeciPt == 0) //no digits after decimal point
        return (false);
        
    return (true);
}

void    showImpossible(void)
{
    std::cout << "char: " << "impossible" << std::endl
              << "int: " << "impossible" << std::endl
              << "float: " << "impossible" <<  std::endl
              << "double: " << "impossible" << std::endl;
}

int handleSpecialCase(const std::string& input)
{
    if (input.empty())
    {
        showImpossible();
    }
    else if (input == "nan" || input == "nanf")
    {
        std::cout << "char: " << "impossible" << std::endl
                  << "int: " << "impossible" << std::endl
                  << "float: " << "nanf" <<  std::endl
                  << "double: " << "nan" << std::endl;
    }
    else if (input == "+inff" || input == "+inf")
    {
        std::cout << "char: " << "impossible" << std::endl
                  << "int: " << "impossible" << std::endl
                  << "float: " << "+inff" <<  std::endl
                  << "double: " << "+inf" << std::endl;
    }
    else if (input == "-inff" || input == "-inf")
    {
        std::cout << "char: " << "impossible" << std::endl
                  << "int: " << "impossible" << std::endl
                  << "float: " << "-inff" <<  std::endl
                  << "double: " << "-inf" << std::endl;
    }
    else
        return (0);
    return (1);
}

void printInt(const std::string input)
{
    int intNum;
    std::stringstream ss(input);

    ss << input;
    ss >> intNum;
    
    if (intNum < 0 || intNum > 127)
        std::cout << "char: " << "impossible" << std::endl;
    else if (intNum > 31 && intNum < 127)
        std::cout << "char: '" << static_cast<char>(intNum) << "'" << std::endl;
    else if ((intNum >=0 && intNum <= 31) || intNum == 127)
        std::cout << "char: " << "Non displayable" << std::endl;

    std::cout << "int: " << intNum << std::endl;

    if (intNum < 1000000 && intNum > -1000000)
    {
        std::cout << "float: " << static_cast<float>(intNum) << ".0f" <<  std::endl;
        std::cout << "double: " << static_cast<double>(intNum) << ".0" << std::endl;
    }
    else
    {
        std::cout << "float: " << static_cast<float>(intNum) << "f" <<  std::endl;
        std::cout << "double: " << static_cast<double>(intNum) << std::endl;
    }
}

void printDouble(const std::string input)
{
    double doubleInput;
    std::stringstream ssD(input);
    bool doubleInf = false;

    ssD << input;
    ssD >> doubleInput;
    if (ssD.fail() || !ssD.eof())
        doubleInf = true;

    std::stringstream ssI(input);
    int intNum;

    ssI >> intNum;
    if (ssI.fail())
    {
        std::cout << "char: impossible" << std::endl
                  << "int: impossible" << std::endl;
    }
    else
    {
        if (intNum < 0 || intNum > 127)
            std::cout << "char: " << "impossible" << std::endl;
        else if (intNum > 31 && intNum < 127 && doubleInput == static_cast<double>(intNum))
            std::cout << "char: '" << static_cast<char>(intNum) << "'" << std::endl;
        else if (((intNum >=0 && intNum <= 31) || intNum == 127) && doubleInput == static_cast<double>(intNum))
            std::cout << "char: " << "Non displayable" << std::endl;
        else 
            std::cout << "char: " << "impossible" << std::endl;

        std::cout << "int: " << intNum << std::endl;
    }

    if (doubleInput == static_cast<double>(intNum))
    {
        std::cout << "float: " << static_cast<float>(doubleInput) << ".0f" <<  std::endl;
        std::cout << "double: " << doubleInput << ".0" << std::endl;
    }
    else
    {
        std::cout << "float: " << static_cast<float>(doubleInput) << "f" <<  std::endl;
        if (doubleInf == 1 && input[0] != '-')
            std::cout << "double: " << "inf" << std::endl;
        else if (doubleInf == 1 && input[0] == '-')
            std::cout << "double: " << "-inf" << std::endl;
        else
            std::cout << "double: " << doubleInput << std::endl;
    }
}

void printChar(const char c)
{
    std::cout << "char: '" << c << "'" << std::endl;

    int intNum = static_cast<int>(c);
    std::cout << "int: " << intNum << std::endl
              << "float: " << static_cast<float>(intNum) << ".0f" <<  std::endl
              << "double: " << static_cast<double>(intNum) << ".0" << std::endl;
}

void ScalarConverter::convert(const std::string& input)
{
    if (handleSpecialCase(input))
        return ;
    else if (is_char(input))
    {
        //std::cout << "Input is a char" << std::endl;
        printChar(input[0]);
        return ;
    }
    else if (is_int(input))
    {
        //std::cout << "Input is a int number" << std::endl;
        printInt(input);
        return ;
    }
    else if (is_float(input))
    {
        //std::cout << "Input is a float" << std::endl;
        printDouble(input.substr(0, input.size()-1));
        return ;
    }
    else if (is_double(input) || (is_digits(input) && !noIntOverflow(input)))
    {
        //std::cout << "Input is a double" << std::endl;
        printDouble(input);
        return ;
    }
    else
    {
        //std::cout << "Invalid input" << std::endl;
        showImpossible();
        return ;
    }
}