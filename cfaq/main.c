//
//
//
#include "stdio.h"


void pChar(char* str)
{
    printf("%s\n", str);
    printf("%d\n", sizeof(str));
}

void pArray(char str[])
{
    str[0] = 'c';
    printf("%s\n", str);
    printf("%d\n", sizeof(str));
}

void main() {
    uint16_t a = 1000, b = 1000;
    long int c = a*b;
    printf("value of a*b = %d\n", c);
    printf("hello world\n");

    char str[] = "hello world";
    printf("%d\n", 3["str"]);
    printf("%d\n", str[3]);

    pChar(str);

    pChar(str);

    pArray(str);

    pArray(str);



}
