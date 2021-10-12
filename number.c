#include <string.h>

#include "number.h"
#include "util.h"

static char const *numbers[] = {
    "zero",    "one",     "two",       "three",    "four",
    "five",    "six",     "seven",     "eight",    "nine",
    "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};

static char const *large_numbers[] = {
    NULL, NULL,
    "twenty",  "thirty", "forty", "fifty", "sixty",
    "seventy", "eighty", "ninety", "one hundred"
};

int
number_from_str(char *tok)
{
    for(int i = 0; i <= 10; ++i)
        if(strcmp(tok, numbers[i]) == 0)
            return i;

    return -1;
}

char const *
number_to_str(int num)
{
    static char outbuf[32];
    char *outbp = outbuf;
    int tens;

    if(num < 20 && num >= 0)
        return numbers[num];

    memset(outbuf, 0, 32);

    if(num < 0){
        outbp += str_write(outbp, "negative ");
        num *= -1;
    }

    if(num < 20){
        str_write(outbp, numbers[num]);
        return outbuf;
    }
    
    tens = num / 10;
    num = num % 10;
    outbp += str_write(outbp, large_numbers[tens]);

    if(num == 0)
        return outbuf;

    *outbp++ = '-';
    str_write(outbp, numbers[num]);
    
    return outbuf;
}