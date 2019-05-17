#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <iostream>

using namespace std;
typedef long long ll;

int N,K;

ll idx[10001];
ll D[10001][1001];


int main()
{
    memset(D,0,sizeof(D));

    scanf("%d\n%d",&N,&K);
    for(int i=0;i<N;i++)
        scanf("%lld",idx+i);
    
    sort(idx,idx+N);

    for(int i=1;i<N;i++)
        D[0][i] = D[0][i-1] + idx[i] - idx[i-1];
    for(int i=1;i<K;i++)
    {
        for(int j=1;j<N;j++)
        {
            D[i][j] = min(D[i-1][j-1], D[i][j-1] + idx[j] - idx[j-1]);
        }
    }

    printf("%lld\n",D[K-1][N-1]);

    return 0;
}