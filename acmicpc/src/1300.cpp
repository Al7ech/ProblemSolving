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

ll N,K;

ll D[100005];

ll count(ll n,ll val)    //  return number of values not larger than val in n*n square
{
    ll &ret = D[n];
    if(ret) return ret;
    if(n == 1) return D[n] = (val>=1);

    return ret = count(n-1,val) + (min((ll)2*n,2*(val/n)) - (val >= n*n));
}

int main()
{
    scanf("%lld",&N);
    scanf("%lld",&K);

    ll min = 1,max = (ll)N*N;
    while(min<max)
    {
        memset(D,0,sizeof(D));
        ll mid = (min+max)/2;

        //printf("%lld %lld %lld %lld\n",min,mid,max,count(N,mid));
        //for(int i=1;i<=N;i++) printf("%d\n",D[i]);

        if(count(N,mid) >= (ll)K)
            max = mid;
        else
            min = mid+1;
    }

    printf("%lld\n",min);

    return 0;
}