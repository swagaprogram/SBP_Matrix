#include <stdio.h>
#include <stdlib.h>
#include <limits>

class Number    
{
public:
                Number(char *numStr);
                Number(int numerator, int denominator);
                Number(double number);
                ~Number();

    bool        checkInputStr(char *numStr);
        
    void        printNumber();
    void        makeNumberSimple();

    bool        Ok() const;

    double      numerator_;
    double      denominator_; 
};

class NumberOperations
{
public:
    Number*     sumNumbers(Number* firstNum, Number* secondNum);
    Number*     subNumbers(Number* firstNum, Number* secondNum);
    Number*     mulNumbers(Number* firstNum, Number* secondNum);
    Number*     divNumbers(Number* firstNum, Number* secondNum);
    bool        checkNumbersEqual(Number* firstNum, Number* secondNum); 
};
