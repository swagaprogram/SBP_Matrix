#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <cmath>

class Number    
{
public:
                Number(char *numStr);
                Number(int numerator, int denominator);
                Number(double number);
                ~Number();

    void        printNumber();

    void        makeNumberSimple();
    int         numerator_;
    int         denominator_;
friend Number operator+(const Number firstNum, const Number secondNum); 
     
private:
    bool        Ok() const;
    bool        checkInputStr(char *numStr);
};

Number*     sumNumbers(Number* firstNum, Number* secondNum);
Number*     subNumbers(Number* firstNum, Number* secondNum);
Number*     mulNumbers(Number* firstNum, Number* secondNum);
Number*     divNumbers(Number* firstNum, Number* secondNum);
bool        checkNumbersEqual(Number* firstNum, Number* secondNum);
int         nok(int a, int b);
int         nod(int a, int b);

