#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int C,N;
int F[25000];

int maxFence(int start,int end)
{
    if(start == end)
        return F[start];
    
    int m = (start+end)/2;

    int min_height = min(F[m],F[m+1]);
    int max_fence = min_height*2;
    int left = m,right = m+1;
    while(right-left<end-start)
    {
        //printf("for : %d %d -> %d\n",left,right,max_fence);
        if(F[left-1] <= F[right+1] && right<end)
        {
            min_height = min(min_height,F[++right]);
            max_fence = max(max_fence,min_height*(right-left+1));
        }
        else if(left>start)
        {
            min_height = min(min_height,F[--left]);
            max_fence = max(max_fence,min_height*(right-left+1));
        }
        
    }
    int ret = max(max_fence, max(maxFence(start,m),maxFence(m+1,end)));
    //printf("%d %d -> %d\n",start,end,ret);
    return ret;
}

int main()
{
    scanf("%d",&C);

    for(int t=0;t<C;t++)
    {
        scanf("%d",&N);

        for(int i=0;i<N;i++)
            scanf("%d",F+i);
        
        printf("%d\n",maxFence(0,N-1));

    }

    return 0;
}