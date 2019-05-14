#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    if (N % 4 == 1 || N % 4 == 2 || N % 4 == 0)
        puts("1");
    else
        puts("2");
    return 0;
}