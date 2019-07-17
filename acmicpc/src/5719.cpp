#include <stdio.h>
#include <queue>
#include <utility>

using namespace std;

int N, M;
vector<pair<int, int>> E[500];
vector<int> visit[500];
int dist[500];
int S, D;

void delEdge(int s,int d);

void dfs(int idx)
{
    for(int next:visit[idx])
    {
        if(next == -1) continue;
        delEdge(next,idx);
        dfs(next);
    }
}
void delEdge(int s,int d)
{
    int len = E[s].size();
    for(int i=0;i<len;i++)
    {
        if(E[s][i].first == d)
        {
            E[s].erase(E[s].begin() + i);
            break;
        }
    }
}

int main(void)
{
    while (1)
    {
        scanf("%d %d", &N, &M);

        if(N == 0 && M == 0)
            break;

        scanf("%d %d", &S, &D);

        for (int i = 0; i < N; i++)
        {
            E[i].clear();
            visit[i].clear();
            dist[i] = 1e+9;
        }

        int U, V, P;
        for (int i = 0; i < M; i++)
        {
            scanf("%d%d%d", &U, &V, &P);
            E[U].push_back(make_pair(V, P));
        }

        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push(make_pair(0, make_pair(-1, S)));
        while (!pq.empty())
        {
            pair<int, pair<int, int>> t = pq.top();
            pq.pop();
            int here = t.second.second;

            if (dist[here] < -t.first)
                continue;
            if (dist[here] == -t.first)
            {
                visit[here].push_back(t.second.first);
                continue;
            }

            dist[here] = -t.first;
            visit[here].push_back(t.second.first);

            for (pair<int, int> edge : E[here])
                if (visit[edge.first].size() == 0)
                    pq.push(make_pair(t.first - edge.second,make_pair(here,edge.first)));
        }
        if(dist[D] == 1e+9) // no answer
        {
            puts("-1");
            continue;
        }
        dfs(D);

        for (int i = 0; i < N; i++)
        {
            visit[i].clear();
            dist[i] = 1e+9;
        }
        pq.push(make_pair(0, make_pair(-1, S)));
        while (!pq.empty())
        {
            pair<int, pair<int, int>> t = pq.top();
            pq.pop();
            int here = t.second.second;

            if (dist[here] < -t.first)
                continue;

            dist[here] = -t.first;
            visit[here].push_back(1e+9);

            for (pair<int, int> edge : E[here])
                if (visit[edge.first].size() == 0)
                    pq.push(make_pair(t.first - edge.second,make_pair(here,edge.first)));
        }
        if(dist[D] == 1e+9) // no answer
        {
            puts("-1");
            continue;
        }
        printf("%d\n",dist[D]);
    }
}