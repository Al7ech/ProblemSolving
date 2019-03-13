#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
ll A[101];

ll tile(int x)
{
    ll &ret = A[x];

    if(ret!=-1)
        return ret;

    if(x == 1)
        return ret = 1;
    if(x == 2)
        return ret = 2;
    return ret = (tile(x-1) + tile(x-2))%MOD;
}
ll asymtile(int x)
{
    ll ret = A[x]-A[x/2];

    if(!(x%2))
        ret -= A[x/2-1];

    while(ret<0)ret+=MOD;

    return ret;
}

int main()
{
    int C;
    scanf("%d",&C);

    memset(A,-1,sizeof(A));
    A[0] = 1;
    tile(100);
    
    for(int t=0;t<C;t++)
    {
        int N;
        scanf("%d",&N);
        printf("%lld\n",asymtile(N));
        
    }
    return 0;
}