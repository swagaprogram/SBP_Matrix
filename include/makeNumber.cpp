#include "makeNumber.h"                                           

makeNumber::makeNumber() {
    counter = 0;
    str = (char*)calloc(100, sizeof(char));
}

void makeNumber::explite() {
    scanStr();
    Data_t val = Counting();
    printf("\n%lg\n", val);
}

void makeNumber::scanStr() {
    printf("#Enter the expression you want to count.\n"); 
    printf("Yes, it is calc.\n"); 
    printf("You can use + - * / ^ ( ).\n");
    printf("Please, no space(I will do it later)\n");
    scanf(" %[^\n]", str);
}

Number* makeNumber::Counting() {
    Number* val = getSubAdd();
    assert(str[counter] == '\0');
    return val;
}

Number* makeNumber::getSubAdd() {
    Number* val = getMulDiv();
    while(str[counter] == '+' || str[counter] == '-') {
        int op = str[counter];
        counter++;
        Number* val2 = getMulDiv();
        if(op == '+') val += val2;
        else val -= val2;
    }
    return val;
}

Data_t makeNumber::getMulDiv() {
    Data_t val = getPower();
    while(str[counter] == '*' || str[counter] == '/') {
        int op = str[counter];
        counter++;
        Data_t val2 = getMulDiv();
        if(op == '*') val *= val2;
        else val /= val2;
    }
    return val;
}

Data_t makeNumber::getPower() {
    Data_t val = getBracketsFunc();
    while(str[counter] == '^') {
        int op = str[counter];
        counter++;
        Data_t val2 = getPower();
        val = pow(val, val2);
    }
    return val;
}

Data_t makeNumber::getBracketsFunc() {
    if (str[counter] == '(') {
        counter++;
        Data_t val = getSubAdd();
        assert(str[counter] == ')');
        counter++;
        return val;
    }
    else return getNumber();
}

Data_t makeNumber::getNumber() {
    Data_t val = 0.0;
    while('0' <= str[counter] && str[counter] <= '9') {
        val = val * 10 + str[counter] - '0';
        counter++;
    }
    if(str[counter] == '.') {
        counter++;
        double i = 0.1;
        while('0' <= str[counter] && str[counter] <= '9') {
            val = val  + i * (str[counter] - '0');
            counter++;
            i *= 0.1;
        }
    }
    return val;
}
