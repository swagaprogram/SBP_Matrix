#include "Number.h" 


Number::Number(char *numStr) :
    numerator_      (std::numeric_limits<double>::quiet_NaN()),
    denominator_    (std::numeric_limits<double>::quiet_NaN())
{
    if(checkInputStr(numStr) == false) {
        printf("Error with input str");
    }
    else { 

    }
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
    numerator_      (number),
    denominator_    (1)
{
    while ((numerator_%1) == 0) {
        numerator_ *= 10;
        denominator_ *= 10;
    }
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

}

bool Number::Ok() const {

}

Number* NumberOperations::sumNumbers(Number* firstNum, Number* secondNum) {
    
}

Number* NumberOperations::subNumbers(Number* firstNum, Number* secondNum) {

}

Number* NumberOperations::mulNumbers(Number* firstNum, Number* secondNum) {
    double newNumerator = firstNum->numerator_ * secondNum->numerator_;
    double newDenominator = firstNum->denominator_ * secondNum->denominator_;
    Number* newNumber = new Number(newNumerator, newDenominator);
    return newNumber;
}

Number* NumberOperations::divNumbers(Number* firstNum, Number* secondNum) {
    double newNumerator = firstNum->numerator_ * secondNum->denominator_;
    double newDenominator = firstNum->denominator_ * secondNum->numerator_;
    Number* newNumber = new Number(newNumerator, newDenominator);
    return newNumber;
}

bool NumberOperations::checkNumbersEqual(Number* firstNum, Number* secondNum) {
    if((firstNum->numerator_ == secondNum->numerator_) && 
        firstNum->denominator_ == secondNum->denominator_) 
        return true;
    else return false;
}    
