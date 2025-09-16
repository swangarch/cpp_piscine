#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& path)
{
    if (_loadDataBase("./data.csv"))
        _loadInput(path);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    *this = other;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        this->_dataBase = other._dataBase;
    return (*this);
}

int     BitcoinExchange::_loadDataBase(const std::string& path)
{
    std::ifstream    inStream(path.data());
    std::string      line;
    std::string      date;
    std::string      valueS;
    double           valueD;
    int              count = 0;

    if (!inStream.good())
    {
        std::cerr << RED << "Error: could not open database." << COLOR_END << std::endl;
        return (0);
    }

    while (!inStream.eof() && inStream.good())
    {
        std::getline(inStream, line);

        if (line.size() > 0)
        {
            if (line.size() < 12)
            {
                std::cerr << RED << "Error: invalid database." << COLOR_END << std::endl;
                inStream.close();
                return (0);
            }
            date = line.substr(0, 10); 
            valueS = line.substr(11, line.size() - 11);
            if (count >= 1 && !_isNumber(valueS))
            {
                std::cerr << RED << "Error: invalid database." << COLOR_END << std::endl;
                inStream.close();
                return (0);
            }
            valueD = this->_strToValue(valueS);
            this->_dataBase[date] = valueD;
            count++;
        }
    }
    inStream.close();
    return (1);
}

int     BitcoinExchange::_isLineValid(const std::string& line) const
{
    if (line.size() <= 0) // empty
        return (0);
    else if (line.size() < 10) // no valid key
        return (-1);
    else if (line.size() < 14) // has valid key but no valid value
        return (-2);
    else if (!this->_isValidDate(line.substr(0, 10))) // data format is not valid
        return (-3);
    else if (!this->_isNumber(line.substr(13, line.size() - 13))) //number format is not valid
        return (-4);
    else if (this->_strToValue(line.substr(13, line.size() - 13)) <= 0) //number is <= 0
        return (-5);
    else if (this->_strToValue(line.substr(13, line.size() - 13)) > 1000) //number is too big
        return (-6);
    else if (line.substr(10, 3) != " | ") // has valid key length but wrong format
        return (-7);

    return (1);
}

std::string     BitcoinExchange::_findClosestDate(const std::string& date) const
{
    std::map<std::string, double>::const_iterator it = this->_dataBase.begin();
    std::map<std::string, double>::const_iterator itNext;

    while (it != this->_dataBase.end())
    {
        itNext = it;
        ++itNext;
        if (date == it->first)
            return (it->first);
        else if (date > it->first)
        {
            if (itNext != this->_dataBase.end() && date < itNext->first)
                return(it->first);
            if (itNext != this->_dataBase.end() && date == itNext->first)
                return(itNext->first);
            else if (itNext == this->_dataBase.end())
                return(itNext->first);
        }
        else if (date < it->first)
            return ("");
        ++it;
    }
    return ("");
}

void    BitcoinExchange::_loadInput(const std::string& path)  //need to be more strict to check date etc
{
    std::ifstream    inStream(path.data());
    std::string      line;
    std::string      date;
    std::string      valueS;
    std::string      closestDate;
    double           valueD;

    if (!inStream.good())
    {
        std::cerr << RED << "Error: could not open file." << COLOR_END << std::endl;
        return;
    }
    if (!inStream.eof())
    {
        std::getline(inStream, line);
        if (line != "date | value")
        {
            std::cerr << RED << "Error: missing header." << COLOR_END << std::endl;
            return;
        }
    }

    int     lineFlag;

    while (!inStream.eof() && inStream.good())
    {
        std::getline(inStream, line);
        lineFlag = _isLineValid(line);

        switch (lineFlag)
        {
            case 1:
                date = line.substr(0, 10);
                valueS = line.substr(13, line.size() - 13);
                valueD = this->_strToValue(valueS);
                closestDate = _findClosestDate(date);
                if (closestDate != "")
                    std::cout << YELLOW << date << " => " << valueD << " = " << this->_dataBase[closestDate] * valueD << COLOR_END << std::endl;
                    // std::cout << YELLOW << closestDate << " => " << valueD << " = " << this->_dataBase[closestDate] * valueD << COLOR_END << std::endl;
                else
                    std::cerr << RED << "Error: no date possible." << COLOR_END << std::endl;
                break;

            case 0:
                std::cerr << RED << "Error: empty line." << COLOR_END << std::endl;
                break;

            case -1:
                std::cerr << RED << "Error: bad input => " << line.substr(0, line.size()) << COLOR_END << std::endl; 
                break;

            case -2:
                std::cerr << RED << "Error: bad input => " << line.substr(0, line.size()) << COLOR_END << std::endl;
                break;

            case -3:
                std::cerr << RED << "Error: bad input => " << line.substr(0, 10) << COLOR_END << std::endl;  
                break;

            case -4:
                std::cerr << RED << "Error: not a number." << COLOR_END << std::endl;
                break;

            case -5:
                std::cerr << RED << "Error: not a positive number." << COLOR_END << std::endl;
                break;

            case -6:
                std::cerr << RED << "Error: too large a number." << COLOR_END << std::endl;   
                break;

            case -7:
                std::cerr << RED << "Error: invalid format." << COLOR_END << std::endl;      
                break;

            default:
                break;
        }   
    }
    inStream.close();
}

bool     BitcoinExchange::_allDigits(const std::string& str) const
{
    for (size_t i = 0; i < str.size(); i++)
        if (!std::isdigit(str[i]))
            return (false);

    return (true);
}

bool     BitcoinExchange::_isValidDate(const std::string& date) const
{
    if (date.size() != 10)
        return (false);
    else if (date[4] != '-' || date[7] != '-')
        return (false);
    
    std::string sYear = date.substr(0,4);
    std::string sMonth = date.substr(5,2);
    std::string sDay = date.substr(8,2);

    if (!this->_allDigits(sYear) && !this->_allDigits(sMonth) && !this->_allDigits(sDay))
        return (false);

    int year = std::atoi(sYear.data());
    int month = std::atoi(sMonth.data());
    int day = std::atoi(sDay.data());

    if (month < 1 || month > 12)
        return (false);
    
    if (day <= 0)
        return (false);

    int maxDay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (day > maxDay[month - 1])
    {
        if (year % 4 == 0 && year % 100 != 0 && month == 2 && day == 29)
            return (true);
        if (year % 400 == 0 && month == 2 && day == 29)
            return (true);
        return (false);
    }
    return (true);
}

double   BitcoinExchange::_strToValue(const std::string& value) const
{
    std::stringstream     ss;
    double      num;  

    ss << value;
    ss >> num;
    return (num);
}

bool     BitcoinExchange::_isNumber(const std::string& str) const
{
    int     numPtDecimal = 0;
    size_t  i = 0;

    if (str.size() == 0)
        return (false);

    if (str[i] == '+' || str[i] == '-')
        i++;

    for (; i < str.size(); i++)
    {
        if (str[i] == '.' && i == str.size() - 1)
            return (false);
        else if (str[i] == '.')
            numPtDecimal++; 
        else if (!std::isdigit(str[i]))
            return (false);
    }
    if (numPtDecimal > 1)
        return(false);
    return (true);
}