#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class   WrongCat : public WrongAnimal
{
    public:
        //__________constructor____________
        WrongCat(void);
        WrongCat(const WrongCat& other);

        //___________destructor____________
        ~WrongCat(void);

        //___________copy assignment operator overload____________
        WrongCat& operator=(const WrongCat& other);

        //______public method______________
        void    makeSound(void) const;
};

#endif