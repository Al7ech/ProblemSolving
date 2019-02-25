#include<stdio.h>

int n;
int val[10000];
int d[10000][3];

int max(int a,int b)
{
    if(a>b) return a;
    return b;
}

int main(void)
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&val[i]);
    d[0][1] = val[0];
    d[1][1] = val[1];
    for(int i=0;i<=n;i++)
    {
        if(i>0) d[i][2] = d[i-1][1] + val[i];
        if(i>1) d[i][1] = d[i-2][0] + val[i];
        d[i][0] = max(d[i][1],d[i][2]);
    }
    printf("%d", max(d[n][0],d[n-1][0]);
    return 0;
}
