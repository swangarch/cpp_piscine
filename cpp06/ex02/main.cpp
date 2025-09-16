#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*   generate(void)
{
    srand(time(NULL));
    int r = rand();

    if (r % 3 == 0)
        return (new A());
    else if (r % 3 == 1)
        return (new B());
    else
        return (new C());

    return (NULL); //never happen
}

void    identify(Base* p)
{
    if (!p)
        std::cout << "invalid pointer" << std::endl;

    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Error: Bad cast" << std::endl;
}

void    identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (std::exception& e)
    {
        try
        {
            (void)dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        }
        catch (std::exception& e)
        {
            try
            {
                (void)dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            }
            catch (std::exception& e)
            {
                std::cout << e.what() << std::endl;
            }
        }
    }
}

int main(void)
{
    Base* ptr = generate();
    Base& ref = *ptr;

    identify(ptr);
    identify(ref);
    
    delete ptr;
    return (0);
}