#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const std::string& input): _nNum(0), _intervalV(0), _intervalD(0)
{
    if (!_parseInput(input))
        throw std::invalid_argument("Error: wrong input.");

    _sortV();
    _sortD();

    if (!checkSorted(_cD))
        throw std::runtime_error("Error: the number in deque are not sorted");
    if (!checkSorted(_cV))
        throw std::runtime_error("Error: the number in vector are not sorted");
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        this->_input = other._input;
        this->_cD = other._cD;
        this->_cV = other._cV;
        this->_nNum = other._nNum;
        this->_intervalV = other._intervalV;
        this->_intervalD = other._intervalD;
    }
    return (*this);
}

void    PmergeMe::_sortV()
{
    struct  timeval start, end;

    //————————————————————————————————————————————————————————————————//
    if (DEBUG_INFO)
        std::cout << YELLOW << "VECTOR________________________________" << COLOR_END << std::endl;
    //————————————————————————————————————————————————————————————————//

    gettimeofday(&start, NULL);

    _copyVtoV();

    if (checkSorted(_cV))
        return ;
    
    _sortContainerAlgo<std::vector<int> >(_cV);

    gettimeofday(&end, NULL);
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    this->_intervalV = seconds * 1000000 + microseconds;
}

void    PmergeMe::_sortD()
{
    struct  timeval start, end;

    //————————————————————————————————————————————————————————————————//
    if (DEBUG_INFO)
        std::cout << YELLOW << "DEQUE_________________________________" << COLOR_END << std::endl;
    //————————————————————————————————————————————————————————————————//

    gettimeofday(&start, NULL);

    _copyVtoD();

    if (checkSorted(_cD))
        return ;

    _sortContainerAlgo<std::deque<int> >(_cD);

    gettimeofday(&end, NULL);
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    this->_intervalD = seconds * 1000000 + microseconds;
}

void    PmergeMe::show()
{
    //--------------Before----------------//
    std::cout << "Before:  ";
    for (size_t i = 0; i < this->_input.size(); i++)
    {
        std::cout << this->_input[i];
        if (i != this->_input.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;

    //--------------After----------------//
    std::cout << "After:   ";
    for (size_t i = 0; i < this->_cV.size(); i++)
    {
        std::cout << this->_cV[i];
        if (i != this->_cV.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;

    //--------------time V----------------//
    std::cout << "Time to process a range of   " << this->_nNum
              << " elements with std::vector : " << this->_intervalV
              << " us" << std::endl;
    
    //--------------time D----------------//
    std::cout << "Time to process a range of   " << this->_nNum
              << " elements with std::deque  : " << this->_intervalD
              << " us" << std::endl;
}

bool     PmergeMe::_parseInput(const std::string& input)
{
    std::string         token;
    std::stringstream   ss(input);
    int                 number;

    while (std::getline(ss, token, ' '))
    {
        std::stringstream   ssToken(token);
        ssToken >> number;
        if (ss.fail())
            throw std::invalid_argument("Error: wrong number.");
        if (std::find(_input.begin(), _input.end(), number) != _input.end())
            throw std::invalid_argument("Error: repeat number.");
        if (number == 0)
            throw std::invalid_argument("Error: not positive number.");

        this->_input.push_back(number);
        this->_nNum++;
    }
    return (true);
}

void    PmergeMe::_copyVtoD()
{
    for (size_t i = 0; i < this->_input.size(); i++)
        this->_cD.push_back(this->_input[i]);
}

void    PmergeMe::_copyVtoV()
{
    for (size_t i = 0; i < this->_input.size(); i++)
        this->_cV.push_back(this->_input[i]);
}