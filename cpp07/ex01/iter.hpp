#ifndef ITER_HPP
#define ITER_HPP

#include <string>

typedef struct s_data //for testing
{
    std::string name;
} data;

template <typename T>
void iter(T* addr, int len, void (*f)(T&))
{
    if (!addr || !f)
        return;
    for (int i = 0; i < len; i++)
        (*f)(addr[i]);
}

#endif