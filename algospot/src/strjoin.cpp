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
vector<int> H;

bool comp(int a,int b)
{
    return a>b;
}

int main()
{
    scanf("%d",&C);
    for(int t=0;t<C;t++)
    {
        H.clear();
        scanf("%d",&N);
        int val;
        for(int i=0;i<N;i++)
        {
            scanf("%d",&val);
            H.push_back(val);
        }
        make_heap(H.begin(),H.end(),comp);

        int f,s;
        int ans = 0;
        for(int i=0;i<N-1;i++)
        {
            f = H[0];
            pop_heap(H.begin(),H.end(),comp);
            H.pop_back();
            s = H[0];
            pop_heap(H.begin(),H.end(),comp);
            H.pop_back();

            ans += f+s;
            H.push_back(f+s);
            push_heap(H.begin(),H.end(),comp);
        }
        printf("%d\n",ans);
    }
    return 0;
}