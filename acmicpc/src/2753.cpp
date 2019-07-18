#include <stdio.h>

int main(void)
{
    int y;
    scanf("%d",&y);
    if((!(y%4) && y%100) || !(y%400))
        puts("1");
    else
        puts("0");
    return 0;
}