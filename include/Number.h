#ifndef NUMBER_H_INCLUDED
#define NUMBER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <string.h>

enum NUMBER_ERRORS {
    ZERO_DENOMINATOR,
    DIV_BY_ZERO,
    UNKNOWN_CHARACTER,
    NO_CLOSING_BRACKET  
};

class Number    
{
public:
                    Number();
                    Number(char *numStr);
                    Number(int numerator, int denominator);
                    Number(double number);
                    Number(int number);
                    ~Number();

    friend Number   operator+(const Number firstNum, const Number secondNum); 
    friend Number   operator-(const Number firstNum, const Number secondNum); 
    friend Number   operator*(const Number firstNum, const Number secondNum); 
    friend Number   operator/(const Number firstNum, const Number secondNum);
           
           Number&  operator=(const Number& copyNum) {
                        this->numerator_ = copyNum.numerator_;
                        this->denominator_ = copyNum.denominator_;
                        return *this;
                    }
           
           Number&  operator=(const int num) {
                        this->numerator_ = num;
                        this->denominator_ = 1;
                        return *this;
                    }

    friend bool     operator==(const Number firstNum, const Number secondNum);
    friend bool     operator!=(const Number firstNum, const Number secondNum);
    
    friend bool     operator>(const Number firstNum, const Number secondNum);
    friend bool     operator>=(const Number firstNum, const Number secondNum);
    friend bool     operator<(const Number firstNum, const Number secondNum);
    friend bool     operator<=(const Number firstNum, const Number secondNum);

    friend std::ostream&    operator<<(std::ostream &output, const Number& number); 

private:
    bool            Ok() const;
    void            makeNumberSimple();
    void            printNumber();

    int             numerator_;
    int             denominator_;

//---------------------------makeNumber.cpp---------------------------------//
    Number          Counting(char *str, size_t *counter);
    Number          getSubAdd(char *str, size_t *counter);
    Number          getMulDiv(char *str, size_t *counter);
    Number          getBracketsFunc(char *str, size_t *counter);
    Number          getPower(char *str, size_t *counter);
    Number          getNumber(char *str, size_t *counter);
//--------------------------------------------------------------------------//
};
    
    int             nok(int a, int b);
    int             nod(int a, int b);
  
#endif
