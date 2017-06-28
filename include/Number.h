#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <assert.h>

class Number    
{
public:
                    Number(char *numStr);
                    Number(int numerator, int denominator);
                    Number(double number);
                    ~Number();

    void            printNumber();
    
    friend Number   operator+(const Number firstNum, const Number secondNum); 
    friend Number   operator-(const Number firstNum, const Number secondNum); 
    friend Number   operator*(const Number firstNum, const Number secondNum); 
    friend Number   operator/(const Number firstNum, const Number secondNum); 
    friend bool     operator==(const Number firstNum, const Number secondNum);
 
private:
    bool            Ok() const;
    bool            checkInputStr(char *numStr);
    void            makeNumberSimple();
    
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





Number*     sumNumbers(Number* firstNum, Number* secondNum);
Number*     subNumbers(Number* firstNum, Number* secondNum);
Number*     mulNumbers(Number* firstNum, Number* secondNum);
Number*     divNumbers(Number* firstNum, Number* secondNum);
bool        checkNumbersEqual(Number* firstNum, Number* secondNum);
