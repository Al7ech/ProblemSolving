#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;
typedef long long ll;

int C;
int N,M;
vector<int> X;

bool able(int val)
{
    int cnt=1;
    int last_cam = X[0];
    for(int i=0;i<M;i++)
    {
        if(last_cam + val <= X[i])
        {
            last_cam = X[i];
            ++cnt;
        }
        if(cnt >= N)
            return true;
    }
    return false;
}

int main()
{
    
    scanf("%d",&C);
    for(int t=0;t<C;t++)
    {
        scanf("%d %d",&N,&M);
        X.clear();
        for(int i=0;i<M;i++)
        {
            float x;
            scanf("%f",&x);
            X.push_back((int)(x*100));
        }

        int min_len = 0;
        int max_len = X[M-1];

        while(min_len < max_len)
        {
            int mid_len = (min_len+max_len+1)/2;

            if(able(mid_len))
                min_len = mid_len;
            else
                max_len = mid_len-1;
        }

        printf("%.2f\n",(float)min_len/100);


    }

    return 0;
}