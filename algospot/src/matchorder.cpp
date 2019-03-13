#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;
typedef long long ll;

int C,N;
vector<int> R,K;
int main()
{
    scanf("%d",&C);
    for(int t=0;t<C;t++)
    {
        R.clear();
        K.clear();
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            int x;
            scanf("%d",&x);
            R.push_back(x);
        }
        for(int i=0;i<N;i++)
        {
            int x;
            scanf("%d",&x);
            K.push_back(x);
        }
        sort(K.begin(),K.end());

        int cnt=0;
        for(int i=0;i<N;i++)
        {
            int val;
            val = R[i];
            int idx = lower_bound(K.begin(),K.end(),val)-K.begin();

            if(idx >= N)
                continue;
            if(K[idx] >= val)
            {
                cnt++;
                K.erase(idx+K.begin());
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}