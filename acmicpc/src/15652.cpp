#include <stdio.h>
#include <vector>

using namespace std;

int N,M;
vector<int> V;

void dfs(int idx,int depth)
{
    V.push_back(idx);

    if(depth == M)
    {
        for(int i : V)
            printf("%d ",i);
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

    for(int i=1;i<=N;i++)
        dfs(i,1);

    return 0;
}