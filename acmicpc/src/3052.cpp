#include <stdio.h>

bool check[42];
int n;
int cnt;

int main(void)
{
    for(int i=0;i<10;i++)
    {
        scanf("%d",&n);
        if(!check[n%42])
        {
            cnt++;
            check[n%42]=1;
        }
    }

    printf("%d\n",cnt);

    return 0;
}