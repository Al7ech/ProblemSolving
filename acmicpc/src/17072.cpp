#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <iostream>

using namespace std;

int N, M;

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int r, g, b;
            scanf("%d %d %d", &r, &g, &b);

            int k = 2126 * r + 7152 * g + 722 * b;

            if (k < 510000)
                printf("#");
            else if (k < 1020000)
                printf("o");
            else if (k < 1530000)
                printf("+");
            else if (k < 2040000)
                printf("-");
            else
                printf(".");
        }
        puts("");
    }
    return 0;
}