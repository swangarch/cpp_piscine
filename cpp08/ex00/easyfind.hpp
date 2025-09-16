#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>

class ElementNotFoundException: std::exception
{
    public:
        virtual const char* what(void) const throw()
        {
            return ("Exception: cannot find second argument in first argument");
        }
};

template< typename T >
typename T::iterator easyfind(T & container, int num)
{
    typename T::iterator it;
    
    it = std::find(container.begin(), container.end(), num);
    if (it == container.end())
        throw ElementNotFoundException();

    return (it);
}

#endif