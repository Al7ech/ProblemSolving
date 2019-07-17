#include <stdio.h>
#include <vector>

using namespace std;

int T,N;
int visit[100005];
int a[100005];

int main(void)
{
    scanf("%d",&T);
    for(int z=0;z<T;z++)
    {
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            visit[i] = -1;
            scanf("%d",a+i);
            a[i]--;
        }
        int ans = 0;
        for(int i=0;i<N;i++)
        {
            if(visit[i]<0)
            {
                vector<int> V;
                int idx = i;
                int cnt = 0;
                while(visit[idx]<0)
                {
                    visit[idx] = cnt++;
                    V.push_back(idx);
                    idx = a[idx];
                }
                if(visit[idx] < cnt && V[visit[idx]] == idx)
                {
                    ans+=visit[idx];
                }
                else
                    ans+=cnt;
            }

        }
        printf("%d\n",ans);
    }
    return 0;
}