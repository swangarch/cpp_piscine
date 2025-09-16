#include <iostream>
#include "Span.hpp"

int main(void)
{
    std::cout << "---------------------Subject test---------------------" << std::endl;

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "---------------------Deep copy---------------------" << std::endl;
    Span*    sp2 = new Span(7);

    sp2->addNumber(123);
    sp2->addNumber(12);
    sp2->addNumber(5);
    sp2->addNumber(1);
    sp2->addNumber(27);
    sp2->addNumber(INT_MAX);
    sp2->addNumber(INT_MIN);

    Span*    sp2_copy = new Span(*sp2);
    delete sp2;
    try
    {
        sp2_copy->addNumber(9);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << sp2_copy->longestSpan() << std::endl;
    std::cout << sp2_copy->shortestSpan() << std::endl;
    
    delete sp2_copy;
    std::cout << "---------------------test 20000---------------------" << std::endl;

    Span sp3 = Span(20000);
    for (int i = 0; i < 20000; i++)
        sp3.addNumber(i);

    std::cout << sp3.shortestSpan() << std::endl;
    std::cout << sp3.longestSpan() << std::endl;

    std::cout << "---------------------test fill range---------------------" << std::endl;

    Span sp4 = Span(20000);

    sp4.addNumber(sp4.begin() + 100, sp4.begin() + 200, 5);
    sp4.addNumber(sp4.begin() , sp4.begin() + 100, 2);
    sp4.addNumber(sp4.begin() + 1000, sp4.begin() + 10000, -10000);
    sp4.addNumber(sp4.begin() + 200, sp4.begin() + 1000, 17);
    sp4.addNumber(sp4.begin() + 10000, sp4.begin() + 19999, 69);

    std::cout << sp4.shortestSpan() << std::endl;
    std::cout << sp4.longestSpan() << std::endl;

    std::cout << "---------------------Zero test---------------------" << std::endl;

    Span sp6 = Span(0);
    try
    {
        sp6.addNumber(123);
        std::cout << sp6.shortestSpan() << std::endl;
        std::cout << sp6.longestSpan() << std::endl;
    }
    catch(std::exception& e)
    {   
        std::cout << e.what() << std::endl;
    }

    return (0);
}

