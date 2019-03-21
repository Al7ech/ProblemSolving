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

int N,K;

int D[100005];

ll count(int n,ll val)    //  return number of values not larger than val in n*n square
{
    int &ret = D[n];
    if(ret) return ret;
    if(n == 1) return D[n] = (val>=1);

    return ret = count(n-1,val) + (val/n - (val > n*n));
}

int main()
{
    scanf("%d",&N);
    scanf("%d",&K);

    ll min = 1,max = N*N;

    while(min<max)
    {
        memset(D,0,sizeof(D));
        ll mid = (min+max)/2;

        if(count(N,mid) > K) 
    }

    return 0;
}