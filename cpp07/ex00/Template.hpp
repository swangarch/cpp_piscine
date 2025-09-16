#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

template < typename T >
void swap(T& x, T& y)
{
    T tmp;

    tmp = x;
    x = y;
    y = tmp;
}

template < typename U >
U const & min(U const & x, U const & y)
{
    return (x < y ? x : y);
}

template < typename V >
V const & max(V const & x, V const & y)
{
    return (x > y ? x : y);
}

#endif