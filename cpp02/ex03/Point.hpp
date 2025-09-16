#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
    public:
        Point(void);
        Point(const float x, const float y);
        Point(const Point& other);
        Point& operator=(const Point& other);
        ~Point(void);

        Fixed get_x(void) const;
        Fixed get_y(void) const;

    private:
        const Fixed _x;
        const Fixed _y;
};

#endif
