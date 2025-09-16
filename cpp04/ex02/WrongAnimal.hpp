#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
    public:
        //__________constructor____________
        WrongAnimal(void);
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal& other);

        //___________destructor____________
        virtual ~WrongAnimal(void);

        //___________copy assignment operator overload____________
        WrongAnimal& operator=(const WrongAnimal& other);

        //______public method______________
        void    makeSound(void) const;

        //_____________getter______________
        std::string getType(void) const;

    protected:
        //______protected attributes_______
        std::string _type;
};

#endif