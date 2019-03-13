#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;
typedef long long ll;


int T,N;
vector<pair<int,int> > L;
int M[10001];

bool comp(pair<int,int> A,pair<int,int> B)
{
    return A.second > B.second;
}

int main()
{
    scanf("%d",&T);

    for(int t=0;t<T;t++)
    {
        L.clear();
        scanf("%d",&N);
        for(int i=0;i<N;i++) scanf("%d",M+i);

        int val;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&val);
            L.push_back(make_pair(M[i],val));
        }
        sort(L.begin(),L.end(),comp);

        int sum = 0;
        int ans = -1;
        for(int i=0;i<N;i++)
        {
            sum+=L[i].first;

            ans = max(ans,sum+L[i].second);
        }
        printf("%d\n",ans);

    }

    return 0;
}