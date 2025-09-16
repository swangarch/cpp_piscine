#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "Addr str: " << &str << std::endl
              << "Addr stringPTR: " << stringPTR << std::endl
              << "Addr stringREF: " << &stringREF << std::endl;

    std::cout << "value str: " << str << std::endl
              << "value stringPTR: " << *stringPTR << std::endl
              << "value stringREF: " << stringREF << std::endl;

    return (0);
}