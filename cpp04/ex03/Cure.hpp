#ifndef CURE_HPP
#define CURE_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class   Cure: public AMateria
{
    public:
        Cure(void);
        Cure(const Cure& other);
        ~Cure(void);

        Cure& operator=(const Cure& other);
        void use(ICharacter& target);
        AMateria* clone(void) const;

    private:
};

#endif