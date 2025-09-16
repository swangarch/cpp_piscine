#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class   Dog : public Animal
{
    public:
        //__________constructor____________
        Dog(void);
        Dog(const Dog& other);

        //___________destructor____________
        ~Dog(void);

        //___________copy assignment operator overload____________
        Dog& operator=(const Dog& other);

        //______public method______________
        void    makeSound(void) const;
};

#endif