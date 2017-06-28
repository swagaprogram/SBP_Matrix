#include <stdio.h>
#include <stdlib.h> 
#include "Number.h"

int main() { 
/*   Number *first = new Number(1,3);
    first->printNumber();
    printf("\n");
    Number *second = new Number(2);
    printf("\n");   
    second->printNumber();*/
    Number FIRST(1, 3);
    Number SECOND(2);
  /*  Number *qw = sumNumbers(first, second);
  */
    Number qw = FIRST + SECOND;
    qw.printNumber();
    printf("\n");
   /* printf("\n");
//    qw->printNumber();
    Number *qwer = new Number(3, 1);
    printf("\n");
    qwer->printNumber();
    delete first;
    delete second;
//    delete qw;
    delete qwer;
    */
    return 0;
}
