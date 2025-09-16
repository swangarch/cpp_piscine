#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->_fixValue = 0;
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;

    int inum = num;

    for (int i = 0; i < this->_fracNum; i++)
        inum *= 2;
    this->_fixValue = inum;
}

Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called" << std::endl;

    float  fnum = num;

    for (int i = 0; i < this->_fracNum; i++)
        fnum *= 2.0;
    this->_fixValue = roundf(fnum);
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_fixValue = other.getRawBits();
    }
    return (*this);
}

int Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixValue);
}

void    Fixed::setRawBits(int const raw)
{
    this->_fixValue = raw;
}

float    Fixed::toFloat(void) const
{
    float floatValue;

    floatValue = this->_fixValue;
    for (int i = 0; i < this->_fracNum; i++)
        floatValue /= 2.0;
    
    return (floatValue);
}

int     Fixed::toInt(void) const
{
    float intValue;

    intValue = this->_fixValue;
    for (int i = 0; i < this->_fracNum; i++)
        intValue /= 2.0;
    
    return (roundf(intValue));
}

const int Fixed::_fracNum = 8;

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}