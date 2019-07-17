#include <stdio.h>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

priority_queue<pair<int, int>> pq;
int N;
int m[150][150];
int dist[20000];
bool visit[20000];

vector<pair<int, int>> E[20000];

void addEdge(int x, int y, int s, int v)
{
    if (x < 0 || y < 0 || x >= N || y >= N)
        return;
    E[s].push_back(make_pair(m[x][y], x * N + y));
    E[x * N + y].push_back(make_pair(v, s));
}

int main(void)
{
    for (int t = 1;; t++)
    {
        scanf("%d", &N);
        if (N == 0)
            break;

        for (int i = 0; i < N * N; i++)
        {
            visit[i] = false;
            dist[i] = 1e+9;
            E[i].clear();
        }
        
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                scanf("%d", &m[i][j]);

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                addEdge(i - 1, j, i * N + j, m[i][j]);
                addEdge(i + 1, j, i * N + j, m[i][j]);
                addEdge(i, j - 1, i * N + j, m[i][j]);
                addEdge(i, j + 1, i * N + j, m[i][j]);
            }
        }


        pq.push(make_pair(0, 0));

        while (!pq.empty())
        {
            pair<int, int> edge = pq.top();
            pq.pop();
            int here = edge.second;

            if (visit[here] || dist[here] <= -edge.first)
                continue;

            dist[here] = -edge.first;
            visit[here] = true;

            for (pair<int, int> e : E[here])
                if (dist[here] + e.first < dist[e.second])
                {
                    pq.push(make_pair(-dist[here] - e.first, e.second));
                }
        }

        printf("Problem %d: %d\n", t, dist[N * N - 1] + m[0][0]);
    }
}