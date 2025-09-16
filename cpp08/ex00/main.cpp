#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <algorithm>
#include <string>

#include "easyfind.hpp"

int main(void)
{
    std::cout << "-------------------vector-------------------" << std::endl;
    std::vector<int>    v1;

    v1.push_back(13);
    v1.push_back(123);
    v1.push_back(19);

    std::vector<int>::iterator itv = easyfind(v1, 19);
    std::cout << *itv << std::endl;

    try 
    {
        itv = easyfind(v1, 20);
        std::cout << *itv << std::endl;
    }
    catch(ElementNotFoundException& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "-------------------list-------------------" << std::endl;
    std::list<int>    l1;

    l1.push_back(13);
    l1.push_back(123);
    l1.push_back(19);

    std::list<int>::iterator itl = easyfind(l1, 19);
    std::cout << *itl << std::endl;

    try 
    {
        itl = easyfind(l1, 20);
        std::cout << *itv << std::endl;
    }
    catch(ElementNotFoundException& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "-------------------deque-------------------" << std::endl;
    std::deque<int>    d1;

    d1.push_back(13);
    d1.push_back(123);
    d1.push_back(19);

    std::deque<int>::iterator itd = easyfind(d1, 19);
    std::cout << *itd << std::endl;

    try 
    {
        itd = easyfind(d1, 20);
        std::cout << *itv << std::endl;
    }
    catch(ElementNotFoundException& e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}