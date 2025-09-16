#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
    std::cout << "--------------------subject test-----------------------" << std::endl;

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);

    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "-------reverse iterator-------"  << std::endl;

    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();

    ++rit;
    --rit;
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }

    std::stack<int> s(mstack); //MutantStack can be instantiate as his parent class std::stack<int>

    std::cout << "--------------------subject test end-----------------------" << std::endl;

    std::cout << "--------------------subject test cmp-----------------------" << std::endl;

    std::list<int> mylist;
    mylist.push_back(5);
    mylist.push_back(17);
    std::cout << mylist.back() << std::endl; 
    mylist.pop_back();
    std::cout << mylist.size() << std::endl;
    mylist.push_back(3);
    mylist.push_back(5);
    mylist.push_back(737);

    mylist.push_back(0);
    std::list<int>::iterator it_list = mylist.begin();
    std::list<int>::iterator ite_list = mylist.end();
    ++it_list;
    --it_list;
    while (it_list != ite_list)
    {
        std::cout << *it_list << std::endl;
        ++it_list;
    }
    //std::stack<int> slist(mylist); //list with deque as underlying container can't be instantiate as std::stack<int>

    std::cout << "-------reverse iterator-------" << std::endl;

    std::list<int>::reverse_iterator rit_list = mylist.rbegin();
    std::list<int>::reverse_iterator rite_list = mylist.rend();

    ++rit_list;
    --rit_list;
    while (rit_list != rite_list)
    {
        std::cout << *rit_list << std::endl;
        ++rit_list;
    }

    std::cout << "--------------------subject test end cmp-----------------------" << std::endl;

    return 0;
}