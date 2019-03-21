#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
typedef long long ll;

typedef struct City
{
    int L,M,G;
}city;

int T;
int N,K;
vector<city> D;

ll count(int x)
{
    ll ret = 0;
    for(city C: D)
    {
        if(x<C.L-C.M)
            ret += 0;
        else if(x<C.L)
            ret += (x-(C.L-C.M))/C.G + 1;
        else
            ret += C.M/C.G + 1;
    }
    return ret; 
}

int main()
{
    scanf("%d",&T);

    for(int t=0;t<T;t++)
    {
        scanf("%d %d",&N,&K);
        D.clear();
        int max_x = -1;
        for(int i=0;i<N;i++)
        {
            city X;
            scanf("%d %d %d",&X.L,&X.M,&X.G);
            D.push_back(X);
            max_x = max(max_x,X.L);
        }
        int min_x = 0;

        while(min_x < max_x)
        {
            int mid_x = (min_x + max_x) / 2;
            if(count(mid_x) >= (ll)K) max_x = mid_x;
            else min_x = mid_x + 1;
        }

        printf("%d\n",min_x);

    }
    return 0;
}