#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

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
        void    setBrainIdeas(std::string idea);
        void    showBrainIdeas(void) const;

        //_____________getter______________
        Brain*  getBrain(void) const;

    private:
        Brain* _brain;
};

#endif