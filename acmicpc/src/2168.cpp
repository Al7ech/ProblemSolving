#include <stdio.h>

int x, y;

int gcd(int x, int y)
{
    if (x)
        return gcd(y % x, x);
    return y;
}

int main(void)
{
    scanf("%d%d", &x, &y);

    printf("%d\n", x + y - gcd(x, y));

    return 0;
}