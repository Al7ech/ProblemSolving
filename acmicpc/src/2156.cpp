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

int P[10001];
int D[10001][2];

int N;

int ans(int idx,bool nextable)
{
    int &ret = D[idx][nextable];

    if(ret != -1)
        return ret;

    if(idx == 0)
        return ret = P[idx];

    if(idx == 1 && nextable)
        return ret = P[idx];

    if(nextable)
        return ret = max( max(ans(idx-2,0),ans(idx-3,0)) , ans(idx-2,1)) + P[idx];
    else
        return ret = ans(idx-1,1) + P[idx];
}

int main()
{
    scanf("%d",&N);

    memset(D,-1,sizeof(D));

    for(int i=0;i<N;i++) scanf("%d",P+i);

    int A = max(ans(N-1,0),ans(N-1,1));
    if(N!=1)
        A = max(A,ans(N-2,0));
    
    printf("%d\n",A);

    return 0;
}