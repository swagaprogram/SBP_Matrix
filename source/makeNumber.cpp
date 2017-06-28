#include "Number.h"                                           

Number Number::Counting(char *str, size_t *counter) {
    Number val = getSubAdd(str, counter);
    assert(str[*counter] == '\0');
    return val;
}

Number Number::getSubAdd(char *str, size_t *counter) {
    Number val = getMulDiv(str, counter);
    while(str[*counter] == '+' || str[*counter] == '-') {
        int op = str[*counter];
        (*counter)++;
        Number val2 = getMulDiv(str, counter);
        if(op == '+') val = val + val2;
        else val = val - val2;
    }
    return val;
}

Number Number::getMulDiv(char *str, size_t *counter) {
    Number val = getPower(str, counter);
    while(str[*counter] == '*' || str[*counter] == '/') {
        int op = str[*counter];
        (*counter)++;
        Number val2 = getMulDiv(str, counter);
        if(op == '*') val = val * val2;
        else val = val / val2;
    }
    return val;
}

Number Number::getPower(char *str, size_t *counter) {
    Number val = getBracketsFunc(str, counter);
    /*
    while(str[] == '^') {
        int op = str[];
        ++;
        Data_t val2 = getPower();
        val = pow(val, val2);
    }
    */
    return val;
}

Number Number::getBracketsFunc(char *str, size_t *counter) {
    if (str[*counter] == '(') {
        (*counter)++;
        Number val = getSubAdd(str, counter);
        assert(str[*counter] == ')');
        (*counter)++;
        return val;
    }
    else return getNumber(str, counter);
}

Number Number::getNumber(char *str, size_t *counter) {
    Number val(0, 1);
    while('0' <= str[*counter] && str[*counter] <= '9') {
        //val = val * 10 + str[] - '0';
        val = val * Number(10, 1) + Number(str[*counter] - '0', 1);
        (*counter)++;
    }
    /*
    if(str[] == '.') {
        ++;
        double i = 0.1;
        while('0' <= str[] && str[counter] <= '9') {
            val = val  + i * (str[] - '0');
            ++;
            i *= 0.1;
        }
    }
    */
    return val;
}
