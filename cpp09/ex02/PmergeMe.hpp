#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <sys/time.h>
#include <stdexcept>
#include <iomanip>
#include <climits>

#include "sortFunction.tpp"

# ifndef COLOR
#  define COLOR

const std::string RED = "\001\033[31m\002";
const std::string YELLOW = "\001\033[33m\002";
const std::string BLUE = "\001\033[1;34m\002";
const std::string GREEN = "\001\033[32m\002";
const std::string COLOR_END = "\001\033[0m\002";
const std::string WHITE_B = "\001\033[1;37m\002";

# endif

class PmergeMe
{
    public:
        PmergeMe(const std::string& input);
        PmergeMe(const PmergeMe& other); 
        ~PmergeMe();

        PmergeMe& operator=(const PmergeMe& other);

        void    show();

    private:
        PmergeMe();

        void    _copyVtoD();
        void    _copyVtoV();
        bool    _parseInput(const std::string& input);
        void    _sortV();
        void    _sortD();

        std::vector<int>      _input;
        std::vector<int>      _cV;
        std::deque<int>       _cD;
        size_t                _nNum;
        time_t                _intervalV;
        time_t                _intervalD;
};

#endif
