#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int map[150][150];
int a[150][150];

int C,N;

int able(int x,int y)
{
    if(x>=N || y>=N)
        return 0;
    if(x==N-1 && y==N-1)
        return 1;
    int &ret = a[x][y];
    if(ret==-1)
        ret = able(x+map[x][y],y) | able(x,y+map[x][y]);
    return ret;
}

int main()
{
    scanf("%d",&C);
    for(int t=0;t<C;t++)
    {
        memset(a,-1,sizeof(a));
        scanf("%d",&N);
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                scanf("%d",&map[i][j]);
        
        printf("%s",able(0,0)?"YES":"NO");
    }
    return 0;
}