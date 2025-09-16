#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
    public:
        //__________constructor____________
        Animal(void);
        Animal(std::string type);
        Animal(const Animal& other);

        //___________destructor____________
        virtual ~Animal(void);

        //___________copy assignment operator overload____________
        Animal& operator=(const Animal& other);

        //______public method______________
        virtual void    makeSound(void) const;

        //_____________getter______________
        std::string getType(void) const;

    protected:
        //______protected attributes_______
        std::string _type;
};

#endif