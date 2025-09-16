#include "Span.hpp"

Span::Span(void) {} //  Private so never be used

Span::Span(unsigned int N): _maxSize(N) {}

Span::Span(const Span& other): _maxSize(other._maxSize)
{
    *this = other;
}

Span::~Span(void) {}

Span&   Span::operator=(const Span& other)
{
    this->_maxSize = other._maxSize;
    this->_vec = other._vec;

    return (*this);
}

void    Span::addNumber(int num)
{
    if (this->_vec.size() >= this->_maxSize)
        throw std::length_error("Exception: can not add number to full span");
    else
        this->_vec.push_back(num);
}

void    Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end, int num)
{
    if (begin < this->_vec.begin() || end >= this->_vec.begin() + this->_maxSize || begin > end)
        throw std::invalid_argument("Invalid iterator");
    
    long pos_begin = begin - this->_vec.begin();
    long pos_end = end - this->_vec.begin(); 
        
    if  (static_cast<unsigned long>(end - this->_vec.begin()) >= this->_vec.size())
        this->_vec.resize(end - this->_vec.begin());

    std::vector<int>::iterator it_begin = this->_vec.begin() + pos_begin;
    std::vector<int>::iterator it_end = this->_vec.begin() + pos_end;

    std::fill(it_begin, it_end, num);
}

unsigned int  Span::shortestSpan(void)
{
    if (this->_vec.size() <= 1)
        throw Span::ImpossibleSpanException();

    unsigned int shortest = UINT_MAX;
    std::vector<int> tmp = this->_vec;
    std::sort(tmp.begin(), tmp.end());

    std::vector<int>::iterator it = tmp.begin();
    std::vector<int>::iterator last_it = it;

    while (it != tmp.end())
    {
        if (static_cast<unsigned int>(*it - *last_it) < shortest && it != last_it)
            shortest = *it - *last_it;
        last_it = it;
        ++it;
    }

    return (shortest);
}

unsigned int  Span::longestSpan(void)
{
    int curr_min = INT_MAX;
    int curr_max = INT_MIN;

    if (this->_vec.size() <= 1)
        throw Span::ImpossibleSpanException();

    for (std::vector<int>::iterator it = this->_vec.begin(); it != this->_vec.end(); ++it)
    {
        if (*it < curr_min)
            curr_min = *it;
        if (*it > curr_max)
            curr_max = *it;
    }
    return (curr_max - curr_min);
}

std::vector<int>::iterator  Span::begin(void)
{
    return (this->_vec.begin());
}

std::vector<int>::iterator  Span::end(void)
{
    return (this->_vec.end());
}

const char* Span::ImpossibleSpanException::what() const throw()
{
    return ("Can not perform span with less than 2 elements.");
}