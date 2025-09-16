#ifndef ICE_HPP
#define ICE_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class   Ice: public AMateria
{
    public:
        Ice(void);
        Ice(const Ice& other);
        ~Ice(void);

        Ice& operator=(const Ice& other);
        void use(ICharacter& target);
        AMateria* clone(void) const;
        
    private:
};

#endif