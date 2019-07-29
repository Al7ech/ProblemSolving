#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);

    int tmp = (N - 1) % 8 + 1;

    if (tmp < 6)
        printf("%d\n", tmp);
    else
        printf("%d\n", 10 - tmp);
    return 0;
}