#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int E,V;
vector<pair<int,int> > G[1005];
vector<pair<int,int> > H;

bool comp(pair<int,int> a,pair<int,int> b)
{
    if(a.first == b.second)
        return a.second < b.second;
    return a.first > b.first;
}

int main()
{
    vector<int> dist(1005,987654321);
    scanf("%d",&V);
    scanf("%d",&E);
    for(int i=0;i<E;i++)
    {
        int src,dst,val;
        scanf("%d %d %d",&src,&dst,&val);
        G[src-1].push_back(make_pair(val,dst-1));
        //G[dst-1].push_back(make_pair(val,src-1));
    }

    int start,end;
    scanf("%d %d",&start,&end);

    H.push_back(make_pair(0,start-1));
    push_heap(H.begin(),H.end(),comp);

    while(!H.empty())
    {
        int val = H[0].first;
        int here = H[0].second;
        pop_heap(H.begin(),H.end(),comp);
        H.pop_back();

        if(dist[here] < val) continue;

        dist[here] = val;

        for(pair<int,int> i:G[here])
        {
            if(dist[i.second] > dist[here] + i.first)
            {
                H.push_back(make_pair(dist[here] + i.first,i.second));
                push_heap(H.begin(),H.end(),comp);
            }
        }
    }

    printf("%d\n",dist[end-1]);

    return 0;
}