#include <stdio.h>

int d[1000005];
int N;

int main(void)
{
    scanf("%d",&N);
    d[1] = 1;
    d[2] = 2;
    for(int i=3;i<=N;i++)
        d[i] = (d[i-2] + d[i-1])% 15746;
    printf("%d\n",d[N]);
    return 0;
}