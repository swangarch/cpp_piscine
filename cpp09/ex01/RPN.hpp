#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <iostream> 

class   Rpn
{   
    public:
        Rpn(const std::string& input);
        Rpn(const Rpn& other);
        ~Rpn();

        Rpn&    operator=(const Rpn& other);

    private:
        Rpn();

        bool    _isValidInput(const std::string& input) const;
        bool    _isOperator(const char& c) const;
        void    _computeRpn(const std::string& input);
        
        std::stack<double> _stk;
};

#endif