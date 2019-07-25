#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
int value[10];
vector<int> V;

void dfs(int idx,int depth)
{
    V.push_back(idx);

    if(depth == M)
    {
        for(int i : V)
            printf("%d ",value[i-1]);
        puts("");
    }
    else
    {
        for(int i=idx;i<=N;i++)
            dfs(i,depth+1);
    }

    V.pop_back();
}

int main(void)
{
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++)
        scanf("%d",value+i);
    sort(value,value+N);

    for(int i=1;i<=N;i++)
        dfs(i,1);

    return 0;
}