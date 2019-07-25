#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
int value[10];
int cnt[20000];
vector<int> V;

void dfs(int idx,int depth)
{
    V.push_back(idx);
    cnt[value[idx]]--;

    if(depth == M)
    {
        for(int i:V)
        {
            printf("%d ",value[i]);
        }
        puts("");
    }
    else
    {
        int prev = -1;

        for(int i=idx+1;i<N;i++)
        {
            if(cnt[value[i]] && prev != value[i])
            {
                dfs(i,depth+1);
                prev = value[i];
            }
        }   
    }

    V.pop_back();
    cnt[value[idx]]++;
}

int main(void)
{
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++)
    {
        scanf("%d",value+i);
        cnt[value[i]]++;
    }
    sort(value,value+N);

    vector<int> visit(10005,0);

    for(int i=0;i<N;i++)
    {
        if(!visit[value[i]])
        {
            visit[value[i]] = 1;
            dfs(i,1);
        }
    }

    return 0;
}