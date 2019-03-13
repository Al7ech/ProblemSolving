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
        sort(R.begin(),R.end());
        reverse(R.begin(),R.end());
        sort(K.begin(),K.end());
        reverse(K.begin(),K.end());
        
        while(!K.empty())
        {
            if(K.back() >= R.back())
                R.pop_back();
            K.pop_back();
        }
        printf("%d\n",N-(int)R.size());
    }
    return 0;
}