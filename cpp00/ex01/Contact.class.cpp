#include "Contact.class.hpp"

const std::string RED = "\001\033[31m\002";
const std::string YELLOW = "\001\033[33m\002";
const std::string COLOR_END = "\001\033[0m\002";

Contact::Contact(void)
{
    _ClearField();
    return;
}

Contact::~Contact(void)
{
    return;
}

void Contact::InputContact(int Index)
{
    this->_Index = Index;

    std::cout << YELLOW << "Enter first name: " << COLOR_END;
    std::getline(std::cin, this->_FirstName);
    if (std::cin.eof()) return ;
    std::cout << YELLOW << "Enter last name: " << COLOR_END;
    std::getline(std::cin, this->_LastName);
    if (std::cin.eof()) return ;
    std::cout << YELLOW << "Enter nick name: " << COLOR_END;
    std::getline(std::cin, this->_NickName);
    if (std::cin.eof()) return ;
    std::cout << YELLOW << "Enter phone number: " << COLOR_END;
    std::getline(std::cin, this->_PhoneNumber);
    if (std::cin.eof()) return ;
    std::cout << YELLOW << "Enter darkest secret: " << COLOR_END;
    std::getline(std::cin, this->_DarkestSecret);
    if (std::cin.eof()) return ;
    _ErrorHandle();
}

void Contact::DisplayContactInTable(void) const
{
    std::cout   << YELLOW << "|"
                << std::setw(10) << std::right << this->_Index << "|"
                << std::setw(10) << std::right << this->_FormatString(this->_FirstName) << "|" 
                << std::setw(10) << std::right << this->_FormatString(this->_LastName) << "|" 
                << std::setw(10) << std::right << this->_FormatString(this->_NickName) << "|" 
                << COLOR_END << std::endl;
    return;
}

void Contact::DisplayContact(void) const
{
    std::cout   << YELLOW
                << "First name: " << this->_FirstName << std::endl
                << "Last name: " << this->_LastName << std::endl
                << "Nick name: " << this->_NickName << std::endl
                << "Phone number: " << this->_PhoneNumber << std::endl
                << "Darkest secret: " << this->_DarkestSecret << std::endl << std::endl
                << COLOR_END;
    return;
}

int Contact::_ErrorCheckName(const std::string string)
{
    for(int i = 0; i < (int)string.length(); i++)
    {
        if (!std::isalpha(string[i]))
        {
            std::cerr << RED <<"Error: non alphabetic name!" << COLOR_END << std::endl;
            return (1);
        }
    }
    return (0);
}

int Contact::_ErrorCheckPhoneNumber(const std::string string)
{
    for(int i = 0; i < (int)string.length(); i++)
    {
        if (!std::isdigit(string[i]))
        {
            std::cerr << RED << "Error: non numeric phone number!" << COLOR_END << std::endl;
            return (1);
        }
        if (string.length() > 15)
        {
            std::cerr << RED << "Error: phone number too long!" << COLOR_END << std::endl;
            return (1);
        }
    }
    return (0);
}

void Contact::_ClearField(void)
{
    this->_FirstName = "";
    this->_LastName = "";
    this->_NickName = "";
    this->_PhoneNumber = "";
    this->_DarkestSecret = "";
}

int Contact::_ErrorHandle(void)
{
    if (!this->_FirstName.length() || !this->_LastName.length() || !this->_NickName.length() || !this->_PhoneNumber.length() || !this->_DarkestSecret.length())// || !this->_DarkestSecret.length())
    {
        std::cerr << RED << "Error: Blank field!" << COLOR_END << std::endl;
        return (_ClearField(), 1);
    }
    if (_ErrorCheckName(this->_FirstName)) return (_ClearField(), 1);
    if (_ErrorCheckName(this->_LastName)) return (_ClearField(), 1);
    if (_ErrorCheckName(this->_NickName)) return (_ClearField(), 1);
    if (_ErrorCheckPhoneNumber(this->_PhoneNumber)) return (_ClearField(), 1);

    return (0);
}

int Contact::HasError(void)
{
    if (!this->_FirstName.length() || !this->_LastName.length() || !this->_NickName.length() || !this->_PhoneNumber.length())// || !this->_DarkestSecret.length())
    {
        return (1);
    }
    return (0);
}

std::string Contact::_FormatString(const std::string& str)
{
    if (str.size() <= 10)
        return (str);
    return (str.substr(0, 9) + ".");
}