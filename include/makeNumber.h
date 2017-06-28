#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>

typedef double Data_t;

class makeNumber
{
public:
    makeNumber();
    ~makeNumber();
    void explite();

	makeNumber& operator= (const makeNumber&);
    makeNumber(const makeNumber&);
private:
    void scanStr();
    
    Data_t Counting();
    Data_t getSubAdd();
    Data_t getMulDiv();
    Data_t getBracketsFunc();
    Data_t getPower();
    Data_t getNumber();

    char*   str;
    size_t  counter;
    
};
