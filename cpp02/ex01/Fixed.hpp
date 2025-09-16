#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <climits>

class Fixed{
    public:
        Fixed(void);
        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed& other);
        ~Fixed(void);

        Fixed& operator=(const Fixed& other);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;

    private:
        int _fixValue;
        static const int _fracNum; 

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);


#endif