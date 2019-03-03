#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <iostream>

using namespace std;

int C,N;

int T[100][100];
int D[100][100];

int maxval(int x,int y)
{
    int &ret = D[x][y];

    if(x==N-1)
        return ret = T[x][y];

    if(ret!=0)
        return ret;
    return ret = max(maxval(x+1,y),maxval(x+1,y+1)) + T[x][y];
}

int main()
{
    scanf("%d",&C);
    for(int t=0;t<C;t++)
    {
        scanf("%d",&N);
        memset(D,0,sizeof(D));

        for(int i=0;i<N;i++) for(int j=0;j<=i;j++) scanf("%d",&T[i][j]);

        printf("%d\n",maxval(0,0));
    }
    return 0;
}