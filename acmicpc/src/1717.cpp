#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
typedef long long ll;

int parent[1000005], height[1000005];

int find(int idx)
{
    if(parent[idx] == idx)
        return idx;
    return find(parent[idx]);
}
void merge(int a,int b)
{
    a = find(a),b = find(b);
    if(a==b) return;

    
    if(height[a] < height[b])
        swap(a,b);
    
    parent[b] = a;
    if(height[a] == height[b]) height[a]++;
}

int N,M;
int main()
{
    scanf("%d %d",&N,&M);

    for(int i=0;i<=N;i++)
    {
        parent[i] = i;
        height[i] = 1;
    }

    for(int i=0;i<M;i++)
    {
        int type,a,b;
        scanf("%d %d %d",&type,&a,&b);


        if(type == 0)
        {
            merge(a,b);
        }
        else
        {
            bool yes = (find(a) == find(b));
            if(yes)
                puts("YES");
            else
                puts("NO");
        }
        
    }

    return 0;
}