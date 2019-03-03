#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <iostream>

using namespace std;

int C,N;

int T[100000];
int D[100000];

int lis(int idx)
{
    int &ret = D[idx];

    if(ret!=0)  return ret;

    ret = 1;

    for(int i=idx+1;i<N;i++)
        if(T[i] > T[idx])
            ret = max(ret,lis(i)+1);

    return ret;
}

int main()
{
    scanf("%d",&C);
    for(int t=0;t<C;t++)
    {
        scanf("%d",&N);
        memset(D,0,sizeof(D));

        for(int i=0;i<N;i++) scanf("%d",&T[i]);

        printf("%d\n",lis(0));
    }
    return 0;
}