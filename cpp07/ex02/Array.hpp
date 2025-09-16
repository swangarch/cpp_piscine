#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <iostream>
#include <stdexcept>

template < typename T = int >
class Array
{
    public:
        Array(void): _size(0), _arr(new T[0]) {}

        Array(unsigned int n): _size(n), _arr(new T[n]) {}

        Array(const Array& other): _size(other.size()), _arr(new T[other.size()])
        {
            *this = other;
        }

        ~Array(void) 
        {
            delete [] this->_arr;
        }

        Array& operator=(const Array& other)
        {
            if (this != &other)
            {
                this->_size = other.size();
                if (this->_arr != NULL)
                    delete [] this->_arr;

                this->_arr = new T[this->_size];
                
                for (unsigned int i = 0; i < this->_size; i++)
                    this->_arr[i] = other.getData()[i];
            }
            return (*this);
        }

        T& operator[](const unsigned int index)
        {  
            if (index >= this->_size)
                throw std::out_of_range("Index out of range!");
            return(this->_arr[index]);
        }

        unsigned int size(void) const
        {
            return (this->_size);
        }

        T*           getData(void) const
        {
            return (this->_arr);
        }

    private:
        unsigned int _size;
        T*           _arr;
};

#endif
