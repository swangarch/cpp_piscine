#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

#include <iostream>
#include <iomanip>
#include "Contact.class.hpp"

class PhoneBook
{
    public:
        PhoneBook(void);
        ~PhoneBook(void);

    private:
        Contact _contacts[8];
        int _index;
        std::string _command;

        void _DisplayContactHeader(void);
        bool _Add(void);
        bool _Search(void);
};

#endif