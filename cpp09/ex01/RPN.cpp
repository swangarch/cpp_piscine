#include "RPN.hpp"

Rpn::Rpn() {}

Rpn::Rpn(const std::string& input)
{
    if (_isValidInput(input))
        this->_computeRpn(input);
    else
        std::cout << "Error" << std::endl;
}

Rpn::Rpn(const Rpn& other)
{
    *this = other;
}

Rpn::~Rpn() {}

Rpn&    Rpn::operator=(const Rpn& other)
{
    if (this != &other)
        this->_stk = other._stk;

    return (*this);
}

void    Rpn::_computeRpn(const std::string& input)
{
    double num1;
    double num2;

    for (size_t i = 0; i < input.size(); i++)
    {
        if (std::isdigit(input[i]))
            this->_stk.push(input[i] - '0');
        
        if (this->_isOperator(input[i]))
        {
            if (this->_stk.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                return ;
            }

            num1 = this->_stk.top();
            this->_stk.pop();
            num2 = this->_stk.top();
            this->_stk.pop();

            if (input[i] == '+')
                this->_stk.push(num2 + num1);
            else if (input[i] == '-')
                this->_stk.push(num2 - num1);
            else if (input[i] == '*')
                this->_stk.push(num2 * num1);
            else if (input[i] == '/')
                this->_stk.push(num2 / num1);
        }
    }
    if (this->_stk.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return ;
    }

    std::cout << this->_stk.top() << std::endl;
}

bool     Rpn::_isOperator(const char& c) const
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return (true);
    return (false);
}

bool     Rpn::_isValidInput(const std::string& input) const
{
    for (size_t i = 0; i < input.size(); i++)
    {
        if (!std::isdigit(input[i]) && i == 0)
            return (0);

        if (i % 2 == 0)
        {
            if (!std::isdigit(input[i]) && !this->_isOperator(input[i]))
                return (0);
        }
        else
        {
            if (input[i] != ' ')
                return (0);
        }
        if (!this->_isOperator(input[i]) && i == input.size() - 1)
            return (0);
    }
    return (1);
}