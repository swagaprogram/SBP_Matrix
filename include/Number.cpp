#include "Number.h" 


Number::Number(char *numStr) :
    numerator_      (0),
    denominator_    (1)
{
   // if(checkInputStr(numStr) == false) {
    //    printf("Error with input str");
   // }
  //  else { 
        size_t counter = 0;    
        Number num = Counting(numStr, &counter);
        numerator_ = num.numerator_;
        denominator_ = num.denominator_;
        makeNumberSimple();
//ok
//    }
}

Number::Number(int numerator, int denominator) : 
    numerator_      (numerator),
    denominator_    (denominator)
{        
    makeNumberSimple();
    if (!Ok()) {
        printf("Error in Number(int numerator, int denominator)");
    }
}

Number::Number(double number) :
    numerator_      (int(number*10000)),
    denominator_    (10000)
{ 
    makeNumberSimple();
    if (!Ok()) {
        printf("Error in Number(double number)");
    }   
}

Number::~Number() {
    numerator_      = -666;
    denominator_    = -666;
}

bool Number::checkInputStr(char *numStr) {
    for (int i = 0; numStr[i] != '/0'; i++) {
        if (!(numStr[i] >= 0 && numStr[i] <= 9) 
            || numStr[i] == '-' || numStr[i] == '.' || numStr[i] == ',') {
                return false;
        }
    }
    return true;
}

void Number::printNumber() {
    if(Ok()) {
        if (denominator_ == 1) 
            printf("%d", numerator_);
        else
            printf("%d/%d", numerator_, denominator_);
    }
}

void Number::makeNumberSimple() {
    int NOD = nod(numerator_, denominator_);
    numerator_ /= NOD;
    denominator_ /= NOD;
}

bool Number::Ok() const {
    return true;
}

int nok(int a, int b) {
    return fabs(a * b) / nod(a, b);
}

int nod(int a, int b) {
    return b ? nod (b, a % b) : a;
}
/*
Number* sumNumbers(Number* firstNum, Number* secondNum) {
    int NOK = nok(firstNum.denominator_, secondNum->denominator_);
    int a = firstNum.numerator_ * (NOK / firstNum-> denominator_);
    int b = secondNum.numerator_ * (NOK / secondNum->denominator_);
    Number* newNumber = new Number(a + b, NOK);
    return newNumber;
}

Number* subNumbers(Number* firstNum, Number* secondNum) {
    int NOK = nok(firstNum.denominator_, secondNum->denominator_);
    int a = firstNum.numerator_ * (NOK / firstNum-> denominator_);
    int b = secondNum.numerator_ * (NOK / secondNum->denominator_);
    Number* newNumber = new Number(a - b, NOK);
    return newNumber;
}

Number* mulNumbers(Number* firstNum, Number* secondNum) {
    int newNumerator = firstNum.numerator_ * secondNum->numerator_;
    int newDenominator = firstNum.denominator_ * secondNum->denominator_;
    Number* newNumber = new Number(newNumerator, newDenominator);
    return newNumber;
}

Number* divNumbers(Number* firstNum, Number* secondNum) {
    int newNumerator = firstNum.numerator_ * secondNum->denominator_;
    int newDenominator = firstNum.denominator_ * secondNum->numerator_;
    Number* newNumber = new Number(newNumerator, newDenominator);
    return newNumber;
}

bool checkNumbersEqual(Number* firstNum, Number* secondNum) {
    if((firstNum.numerator_ == secondNum->numerator_) && 
        firstNum.denominator_ == secondNum->denominator_) 
        return true;
    else return false;
}
*/

Number operator+(const Number firstNum, const Number secondNum) {
    int NOK = nok(firstNum.denominator_, secondNum.denominator_);
    int a = firstNum.numerator_ * (NOK / firstNum.denominator_);
    int b = secondNum.numerator_ * (NOK / secondNum.denominator_);
    Number newNumber(a + b, NOK);
    return newNumber;
}

Number operator-(const Number firstNum, const Number secondNum) {
    int NOK = nok(firstNum.denominator_, secondNum.denominator_);
    int a = firstNum.numerator_ * (NOK / firstNum.denominator_);
    int b = secondNum.numerator_ * (NOK / secondNum.denominator_);
    Number newNumber(a - b, NOK);
    return newNumber;
}

Number operator*(const Number firstNum, const Number secondNum) {
    int newNumerator = firstNum.numerator_ * secondNum.numerator_;
    int newDenominator = firstNum.denominator_ * secondNum.denominator_;
    Number newNumber(newNumerator, newDenominator);
    return newNumber;
}

Number operator/(const Number firstNum, const Number secondNum) {
    int newNumerator = firstNum.numerator_ * secondNum.denominator_;
    int newDenominator = firstNum.denominator_ * secondNum.numerator_;
    Number newNumber(newNumerator, newDenominator);
    return newNumber;
}

bool operator==(const Number firstNum, const Number secondNum) {
     if((firstNum.numerator_ == secondNum.numerator_) && 
        firstNum.denominator_ == secondNum.denominator_) 
        return true;
    else return false;
}
