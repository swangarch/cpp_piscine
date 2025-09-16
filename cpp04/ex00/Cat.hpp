#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class   Cat : public Animal
{
    public:
        //__________constructor____________
        Cat(void);
        Cat(const Cat& other);

        //___________destructor____________
        ~Cat(void);

        //___________copy assignment operator overload____________
        Cat& operator=(const Cat& other);

        //______public method______________
        void    makeSound(void) const;
};

#endif