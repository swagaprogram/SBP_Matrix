#include <stdio.h>
#include <stdlib.h> 
#include "Number.h"

int main() { 
    Number FIRST("1/3+(1+1)");
    Number SECOND(2);
    Number qw = FIRST - SECOND;
    qw.printNumber();
    printf("\n");
    FIRST = FIRST + SECOND;
    FIRST.printNumber();
    return 0;
}
