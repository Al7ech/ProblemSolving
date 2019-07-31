#include <stdio.h>

int a, m;

int main(void)
{
    scanf("%d %d", &a, &m);

    for (int i = 1;; i++)
        if ((i * a) % m == 1)
        {
            printf("%d\n", i);
            return 0;
        }

    return 0;
}