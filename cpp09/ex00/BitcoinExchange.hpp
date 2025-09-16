#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include <map>
# include <cstdlib>
# include <iterator>

# ifndef COLOR
#  define COLOR

const std::string RED = "\001\033[31m\002";
const std::string YELLOW = "\001\033[33m\002";
const std::string COLOR_END = "\001\033[0m\002";

# endif

class   BitcoinExchange 
{
    public:
        BitcoinExchange(const std::string& path);
        BitcoinExchange(const BitcoinExchange& other);
        ~BitcoinExchange();

        BitcoinExchange& operator=(const BitcoinExchange& other);

    private:
        BitcoinExchange();

        int         _loadDataBase(const std::string& path);
        void        _loadInput(const std::string& path);

        std::string _findClosestDate(const std::string& date) const;
        bool        _isValidDate(const std::string& date) const;
        bool        _isNumber(const std::string& str) const;
        double      _strToValue(const std::string& value) const;
        int         _isLineValid(const std::string& line) const;
        bool        _allDigits(const std::string& str) const;

        std::map<std::string, double>   _dataBase;
};

#endif