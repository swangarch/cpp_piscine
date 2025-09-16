#include "Point.hpp"

Point::Point(void) : _x(Fixed(0)), _y(Fixed(0))
{
    ;
}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y))
{
    ;
}

Point::Point(const Point& other) : _x(other.get_x()), _y(other.get_y())
{
    ;
}

Point& Point::operator=(const Point& other)
{
    (void)other;
    return (*this);
}

Point::~Point(void)
{
    ;
}

Fixed Point::get_x(void) const
{
    return (this->_x);
}

Fixed Point::get_y(void) const
{
    return (this->_y);
}