#include <iostream>
#include <string>
#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: incorrect argumet number!" << std::endl;
        return (1);
    }

    const int DEBUG = 0;
    const int INFO = 1;
    const int WARNING = 2;
    const int ERROR = 3;

    Harl harl;
    std::string level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    int i = 0;
    for (i = 0; i < 4; i++)
        if (argv[1] == level[i])
            break ;
    
    switch (i)
    {
        case (DEBUG) :
            std::cout << "[ DEBUG ]" << std::endl;
            harl.complain(level[DEBUG]);
            std::cout << std::endl;
            // fall through
        
        case (INFO) : 
            std::cout << "[ INFO ]" << std::endl;
            harl.complain(level[INFO]);
            std::cout << std::endl;
            // fall through
        
        case (WARNING) : 
            std::cout << "[ WARNING ]" << std::endl;
            harl.complain(level[WARNING]);
            std::cout << std::endl;
            // fall through
        
        case (ERROR) : 
            std::cout << "[ ERROR ]" << std::endl;
            harl.complain(level[ERROR]);
            std::cout << std::endl;
            break ;
        
        default : 
            std::cout << "[ Probably complaining about insingnificant problems ]" << std::endl;
            break ;
    }
    return (0);
}