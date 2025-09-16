#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
    public:
        //___________destructor____________
        virtual ~AAnimal(void);

        //___________copy assignment operator overload____________
        AAnimal& operator=(const AAnimal& other);

        //______public method______________
        virtual void    makeSound(void) const = 0;

        //_____________getter______________
        std::string getType(void) const;

    protected:
        //__________constructor____________
        AAnimal(void);
        AAnimal(std::string type);
        AAnimal(const AAnimal& other);

        //______protected attributes_______
        std::string _type;
};

#endif