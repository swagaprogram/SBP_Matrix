#include "./../include/Number.h" 

Number::Number() :
    numerator_      (0),
    denominator_    (1)
{}

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
   /* try {
        if(Ok()) {}
        else {
            throw "denominator = 0, div by zero\n";
        }
    }
    catch(char *msg) {
        printf(msg);
        Number();
    }
    */
}

Number::Number(double number) :
    numerator_      (int(number*10000)),
    denominator_    (10000)
{ 
    makeNumberSimple();
/*    try {
        if(Ok()) {}
        else {
            throw "denominator = 0, div by zero\n";
        }
    }
    catch(char *msg) {
        printf(msg);
    }
    */
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
    if(denominator_ == 0) return false;
    else return true;
}

int nok(int a, int b) {
    return fabs(a * b) / nod(a, b);
}

int nod(int a, int b) {
    return b ? nod (b, a % b) : a;
}

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

bool operator!=(const Number firstNum, const Number secondNum) {
    if((firstNum.numerator_ == secondNum.numerator_) && 
        firstNum.denominator_ == secondNum.denominator_) 
        return false;
    else return true;
}   

bool operator>(const Number firstNum, const Number secondNum) {
    int NOK = nok(firstNum.denominator_, secondNum.denominator_);
    int a = firstNum.numerator_ * (NOK / firstNum.denominator_);
    int b = secondNum.numerator_ * (NOK / secondNum.denominator_);
    if (a > b) return true;
    else return false;
}

bool operator>=(const Number firstNum, const Number secondNum) {
    int NOK = nok(firstNum.denominator_, secondNum.denominator_);
    int a = firstNum.numerator_ * (NOK / firstNum.denominator_);
    int b = secondNum.numerator_ * (NOK / secondNum.denominator_);
    if (a >= b) return true;
    else return false;
}

bool operator<(const Number firstNum, const Number secondNum) {
    int NOK = nok(firstNum.denominator_, secondNum.denominator_);
    int a = firstNum.numerator_ * (NOK / firstNum.denominator_);
    int b = secondNum.numerator_ * (NOK / secondNum.denominator_);
    if (a < b) return true;
    else return false;
}

bool operator<=(const Number firstNum, const Number secondNum) {
    int NOK = nok(firstNum.denominator_, secondNum.denominator_);
    int a = firstNum.numerator_ * (NOK / firstNum.denominator_);
    int b = secondNum.numerator_ * (NOK / secondNum.denominator_);
    if (a <= b) return true;
    else return false;
}
