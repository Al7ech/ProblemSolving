#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int c;
int n,m;
int a,b;

vector<pair<int,int> > friend_pair;

bool sortbyFirst(pair<int,int> f, pair<int,int> s)
{
    if(f.first == s.first)
        return f.second < s.second;
    return f.first < s.first;
}

int rec_ans(bool status[10],int lastidx,int pairs)
{
    if(pairs == n/2)
        return 1;
    
    int ret = 0;

    for(int i=lastidx+1;i<m;i++)
    {
        if(status[friend_pair[i].first] || status[friend_pair[i].second]) continue;
        status[friend_pair[i].first] = status[friend_pair[i].second] = 1;
        ret += rec_ans(status,i,pairs+1);
        status[friend_pair[i].first] = status[friend_pair[i].second] = 0;
    }
    return ret;

}

int main()
{

    scanf("%d",&c);
    
    for(int t = 0; t < c; t++)
    {
        friend_pair.clear();
        scanf("%d %d",&n,&m);

        for(int i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            if(a>b)
                swap(a,b);
            friend_pair.push_back(make_pair(a,b));
        }

        sort(friend_pair.begin(),friend_pair.end(),sortbyFirst);

        bool status[10] = {0,};

        printf("%d\n",rec_ans(status,-1,0));
        
    }

    return 0;
}