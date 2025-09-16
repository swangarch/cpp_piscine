#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP

#include <iostream>
#include <string>
#include <iomanip>

extern const std::string RED;
extern const std::string YELLOW;
extern const std::string COLOR_END;

class Contact
{
    public:
        Contact(void);
        ~Contact(void);

        void InputContact(int Index);
        void DisplayContactInTable(void) const;
        void DisplayContact(void) const;
        int HasError(void);
    
    private:
        int _Index;
        std::string _DarkestSecret;
        std::string _FirstName;
        std::string _LastName;
        std::string _NickName;
        std::string _PhoneNumber;

        static int _ErrorCheckName(const std::string string);
        static int _ErrorCheckPhoneNumber(const std::string string);
        static std::string _FormatString(const std::string& str);
        int _ErrorHandle(void);
        void _ClearField(void);
};

#endif