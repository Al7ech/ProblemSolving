#include <stdio.h>

long long fib[95];

int main(void)
{
    fib[1] = 1;
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }
    printf("%lld\n",fib[n]);
    return 0;
}