#ifndef SPAN_HPP
#define SPAN_HPP

#include <stdexcept>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>

class   Span
{
    public:
        Span(unsigned int N);
        Span(const Span& other);
        ~Span(void);

        Span& operator=(const Span& other);

        void          addNumber(int num);
        void          addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end, int num);
        unsigned int  shortestSpan(void);
        unsigned int  longestSpan(void);

        std::vector<int>::iterator  begin(void);
        std::vector<int>::iterator  end(void);

        class ImpossibleSpanException: std::exception
        {
            public:
                virtual const char* what() const throw();
        };

    private:
        Span(void);

        unsigned int        _maxSize;
        std::vector<int>    _vec;
};

#endif