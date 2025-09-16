#ifndef SORT_FUNCTION_TPP
#define SORT_FUNCTION_TPP

#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <iomanip>
#include <algorithm>

# define  DEBUG_INFO false

# ifndef COLOR
#  define COLOR

const std::string RED = "\001\033[31m\002";
const std::string YELLOW = "\001\033[33m\002";
const std::string BLUE = "\001\033[1;34m\002";
const std::string GREEN = "\001\033[32m\002";
const std::string COLOR_END = "\001\033[0m\002";
const std::string WHITE_B = "\001\033[1;37m\002";

# endif

//----------------------------------------For debug-------------------------------------------//

template <typename T>
bool    checkSorted(T& input)  
{
    if (input.size() < 2)
        return (true);
    for (size_t i = 0; i < input.size() - 1; i++)
    {
        if (input[i] > input[i + 1])
            return (false);
    }
    return (true);
}

template <typename T>
void    printContainer(std::string info, const T& data, const std::string& color)
{
    size_t  sz = data.size();
    size_t  i = 0;

    std::cout << color << info << std::endl
              << "TOP  ";
    for (; i < sz / 2; i++)
        std::cout << std::left << std::setw(8) << data[i];
    std::cout << std::endl << "BOT  ";
    for (; i < sz; i++)
        std::cout << std::left << std::setw(8) << data[i];
    std::cout << COLOR_END << std::endl << std::endl;
}

template <typename T>
void printContainerSimple(std::string title, const T& data, const std::string& color)
{
    size_t  sz = data.size();
    size_t  i = 0;

    std::cout << color << title << "  ";
    for (; i < sz; i++)
        std::cout << data[i] << " ";
    std::cout << color << std::endl;
}

//----------------------------------------For debug-------------------------------------------//

template <typename T>
int LessThanTwo(T& data)
{
    if (data.size() <= 1)
        return 1;
    else if (data.size() == 2)
    {
        if (data[0] > data[1])
            return (std::swap(data[0], data[1]), 1);
        else
            return 1;
    }
    return 0;
}

template <typename T>
T jacobsthal(size_t n)
{
    T       series;
    int     num;

    if (n < 1)
        return series;
    series.push_back(0);
    if (n == 1)
        return series;
    series.push_back(1);
    if (n == 2)
        return series;

    for (size_t i = 2; i < n; i++)
    {
        num = series[i - 1] + 2 * series[i - 2];
        series.push_back(num);
    }
    // //————————————————————————————————————————————————————————————————//
    // if (DEBUG_INFO)
    //     printContainerSimple("JACOBSTHAL: ", series, BLUE);
    // //————————————————————————————————————————————————————————————————//
    return series;
}

template <typename T>
T insertionOrder(size_t size)
{
    T       jacobSeries = jacobsthal<T>(33);
    T       order;
    int     right;
    int     left;
    size_t  num = (size % 2) ? (size / 2 + 1) : (size / 2);
    
    order.push_back(0);
    for (size_t i = 2; i < jacobSeries.size(); i++)
    {
        right = jacobSeries[i + 1] - 1;
        left = jacobSeries[i] - 1;
        while (right > left)
        {
            if (static_cast<size_t>(right) < num)
                order.push_back(right);
            right--;
        }
        if (size >= static_cast<size_t>(jacobSeries[i]) && size < static_cast<size_t>(jacobSeries[i + 1]))
            break;
    }
    // //————————————————————————————————————————————————————————————————//
    // if (DEBUG_INFO)
    //     printContainerSimple("INSERTION ORDER: ", order, BLUE);
    // //————————————————————————————————————————————————————————————————//
    return order;
}

template <typename T>
void insertPos(T& sorted, int number, int boundary)
{
    int     left = 0;
    int     right = boundary - 1;
    int     middle = right / 2;

    while (right - left > 1)
    {
        middle = left + (right - left) / 2;
        if (number > sorted[left] && number < sorted[middle])
            right = middle;
        else if (number > sorted[middle] && number < sorted[right])
            left = middle;
        else if (number > sorted[right])
            left = right;
        else if (number < sorted[left])
            right = left;
        else
            throw std::invalid_argument("Error: insertion");  //Never happen
    }
    if (number < sorted[left])
        sorted.insert(sorted.begin() + left, number);
    else if (number > sorted[right])
        sorted.insert(sorted.begin() + right + 1, number);
    else
        sorted.insert(sorted.begin() + left + 1, number);
}

template <typename T>
void createIndice(T& data, T& indice)
{
    for (size_t i = 0; i < data.size(); i++)
        indice.push_back(static_cast<int>(i));
}

template <typename T>
void binaryInsert(T& data)
{
    T       sorted;
    T       order;
    size_t  size;
    size_t  numberRightChain;
    int     nextIdx;

    size = data.size() / 2;
    order = insertionOrder<T>(data.size());

    for (size_t i = 0; i < size; i++)
        sorted.push_back(data[i]);

    numberRightChain = (data.size() % 2) ? (size + 1) : size;

    for (size_t i = 0; i < numberRightChain; i++)
    {
        nextIdx = order[i] + size;
        insertPos(sorted, data[nextIdx], order[i] + i);
    }
    data = sorted;
}

template <typename T>
T getSubChain(T& original, size_t start, size_t end)
{
    T   target;

    for (size_t i = start; i < end; i++)
        target.push_back(original[i]);

    return target;
}

template <typename T>
T joinContainer(T& first, T& second)
{
    T   res;

    for (size_t i = 0; i < first.size(); i++)
        res.push_back(first[i]);
    for (size_t i = 0; i < second.size(); i++)
        res.push_back(second[i]);

    return res;
}

template <typename T>
void    arrangeByIndice(T& sortedIndiceTemp, T& right)
{
    T   arrangedRight(right.size(), 0);

    if (sortedIndiceTemp.size() == 0)
        return;

    for (size_t i = 0; i < sortedIndiceTemp.size(); i++)
        arrangedRight[sortedIndiceTemp[i]] = right[i];

    right = arrangedRight;
}

template <typename T>
size_t  getIndex(T& data, int element)
{
    for (size_t i = 0; i < data.size(); i++)
        if (element == data[i])
            return i;
    
    throw std::invalid_argument("Error: invalid number in get index");  //Never happen
}

template <typename T>
T getIndexArr(T& before, T& after)
{
    T   indices(before.size(), 0);

    for (size_t i = 0; i < before.size(); i++)
        indices[i] = getIndex(after, before[i]);

    return indices;
}

template <typename T>
void _sortContainerAlgo(T& data)
{
    if (LessThanTwo(data))
        return;
    
    size_t  chainSize = data.size() / 2;
    int     oddNumber = data.size() % 2;
    int     lastElement = data[data.size() - 1];

    for (size_t i = 0; i < chainSize; i++)
    {
        if (data[i] < data[i + chainSize])
            std::swap(data[i], data[i + chainSize]);
    }

    //————————————————————————————————————————————————————————————————//
    if (DEBUG_INFO)
        printContainer("BEFORE", data, RED);
    //————————————————————————————————————————————————————————————————//

    T   left = getSubChain(data, 0, chainSize);
    T   copyleft = left;
    T   right = getSubChain(data, chainSize, chainSize * 2);

    _sortContainerAlgo(left);

    T   sortedIndiceTemp = getIndexArr(copyleft, left);
    arrangeByIndice(sortedIndiceTemp, right);

    data = joinContainer(left, right);
    if (oddNumber)
        data.push_back(lastElement);

    //————————————————————————————————————————————————————————————————//
    if (DEBUG_INFO)
        printContainer("BEFORE INSERTON", data, RED);
    //————————————————————————————————————————————————————————————————//

    binaryInsert(data);

    //————————————————————————————————————————————————————————————————//
    if (DEBUG_INFO)
        printContainer("AFTER", data, RED);
    //————————————————————————————————————————————————————————————————//
}

#endif