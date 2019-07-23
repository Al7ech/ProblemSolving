#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N,M;
int visit[10];
int value[10];
char dup[17000000];
vector<int> V;

int calc()
{
    int ret = 0;
    for(int i=0;i<M;i++)
        ret+= (V[i]-1) << 3*i;

    return ret;
}

void dfs(int idx,int depth)
{
    V.push_back(idx);
    visit[idx] = 1;

    if(depth == M)
    {
        printf("%d %d\n",idx,calc());
        dup[calc()] = 1;
    }
    else
    {
        for(int i=1;i<=N;i++)
        {
            if(!visit[i])
                dfs(i,depth+1);
        }
    }

    V.pop_back();
    visit[idx] = 0;
}

int main(void)
{
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++)
        scanf("%d",value+i);
    sort(value,value+N);

    for(int i=1;i<=N;i++)
        dfs(i,1);

    int len = (int)(pow(N,M)+0.5);

    for(int i=0;i<len;i++)
    {
        if(dup[i])
        {
            printf("PA : %d\n",i);
            int tmp = i;
            for(int j=0;j<M;j++)
            {
                printf("%d ",value[tmp%8]);
                tmp >>= 3;
            }
            puts("");
        }
    }

    return 0;
}