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

int C;
int N;
vector<pair<double,double> > S;
int x,y;
double len_sq[100][100];
bool able_to[100][100];
queue<int> Q;

inline double sq(int idx,int idy)
{
    return (S[idx].first-S[idy].first)*(S[idx].first-S[idy].first) + (S[idx].second-S[idy].second)*(S[idx].second-S[idy].second);
}

bool able(double val)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(len_sq[i][j] > val) able_to[i][j] = false;
            else able_to[i][j] = true;
        }
    }

    bool visited[100] = {0,};
    int cnt=1;
    Q.push(0);
    visited[0] = 1;
    while(Q.size())
    {
        int current_idx = Q.front();
        Q.pop();
        for(int i=0;i<N;i++)
        {
            if(current_idx != i && able_to[current_idx][i] && !visited[i])
            {
                Q.push(i);
                cnt++;
                visited[i] = true;
            }
        }
    }
    if(cnt==N)
        return true;
    return false;
}

int main()
{
    scanf("%d",&C);

    for(int t=0;t<C;t++)
    {
        scanf("%d",&N);
        S.clear();
        double x,y;
        for(int i=0;i<N;i++)
        {
            scanf("%lf %lf",&x,&y);
            S.push_back(make_pair(x,y));
        }
        double min_dir = 0;
        double max_dir = -1;
        for(int i=0;i<N;i++) for(int j=0;j<N;j++) len_sq[i][j] = sq(i,j);
        for(int i=0;i<N;i++) for(int j=0;j<N;j++) max_dir = max(max_dir,len_sq[i][j]);

        for(int i=0;i<150;i++)
        {
            double mid_dir = (min_dir + max_dir) / 2.0;
            
            if(able(mid_dir))
                max_dir = mid_dir;
            else
                min_dir = mid_dir;
        }
        printf("%.2lf\n",sqrt(min_dir));
    }
    return 0;
}