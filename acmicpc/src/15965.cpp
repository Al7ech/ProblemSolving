#include <stdio.h>

int K, cnt;
bool A[10000000];

int main(void)
{
    scanf("%d", &K);

    int i;
    for (i = 2;; i++)
    {
        if (!A[i])
        {
            cnt++;
            if (cnt == K)
                break;
            for (int j = i * 2; j < 10000000; j += i)
                A[j] = 1;
        }
    }

    printf("%d\n", i);

    return 0;
}