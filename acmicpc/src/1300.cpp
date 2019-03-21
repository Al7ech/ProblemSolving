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

ll D[100005];
int cnt;

ll count(int n,ll val)    //  return number of values not larger than val in n*n square
{
    //printf("%d %d\n",n,cnt);
    ll &ret = D[n];
    if(ret) return ret;
    cnt++;
    if(n == 1) return D[n] = (val>=1);

    return ret = count(n-1,val) + (min((ll)2*n,2*(val/n)) - (val >= n*n));
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

        //rintf("%lld %lld %lld %lld\n",min,mid,max,count(N,mid));
        //for(int i=1;i<=N;i++) printf("%d\n",D[i]);

        if(count(N,mid) >= (ll)K)
            max = mid;
        else
            min = mid+1;
    }

    printf("%lld\n",min);

    return 0;
}