#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;

int C,N,S;
int A[100];

int D[100][11];
int SS[101],SS2[101];

int minError(int start,int end)
{
    int ans_val = round(float(SS[end+1]-SS[start])/(end-start+1));

    return (end-start+1)*ans_val*ans_val - 2 * ans_val *(SS[end+1]-SS[start]) + (SS2[end+1]-SS2[start]);

}

int ans(int fidx,int part)
{
    if(part == 0)
        return 987654321;

    int &ret = D[fidx][part];
    if(ret != -1)
        return ret;
    if(part == 1)
        return ret = minError(fidx,N-1);

    if(fidx == N-1)
        return ret = 0;

    ret = 987654321;

    for(int i = fidx+1;i<N;i++)
    {
        ret = min(ret,minError(fidx,i-1)+ans(i,part-1));
    }
    return ret;
}

int main()
{
    scanf("%d",&C);

    for(int t=0;t<C;t++)
    {
        memset(D,-1,sizeof(D));
        memset(SS,0,sizeof(SS));

        scanf("%d %d",&N,&S);
        for(int i=0;i<N;i++) scanf("%d",A+i);

        sort(A,A+N);

        for(int i=0;i<N;i++) SS[i+1] = SS[i] + A[i];
        for(int i=0;i<N;i++) SS2[i+1] = SS2[i] + A[i]*A[i];


        printf("%d\n",ans(0,S));
    }

    return 0;
}