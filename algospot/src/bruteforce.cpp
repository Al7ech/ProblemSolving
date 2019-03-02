#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int C,A,B,N;

ll pow(int N,int X) // return N^X (lgX);
{
    if(X==1) return (ll)N;
    ll half = pow(N,X/2);
    ll ret = (half*half)%MOD;
    if(X%2) return (ret*N)%MOD;
    return ret;
}

ll sigma(int N,int X)   // return sigma(from k=1 to k=X) N^k (lgX)
{
    if(X==0) return 0;
    if(X==1) return N;
    ll ret = sigma(N,X/2)*(1+pow(N,X/2))%MOD;
    if(X%2) ret = (ret+pow(N,X))%MOD;
    return ret;
}

ll bruteForce(int N,int A,int B)
{
    ll ans = sigma(N,B)-sigma(N,A-1);

    return ans + MOD*(ans<0);
}

int main()
{
    scanf("%d",&C);
    for(int t=0;t<C;t++)
    {
        scanf("%d %d %d",&A,&B,&N);
        printf("%lld\n",bruteForce(N,A,B));
    }
    return 0;
}