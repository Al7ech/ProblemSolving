#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <iostream>

using namespace std;
typedef long long ll;

typedef struct edge
{
    edge(int U, int V, int W)
    {
        u = U, v = V, w = W;
    }
    int u, v, w;
} Edge;
int N, M, K;
int parent[1005];
vector<Edge> E;

bool comp(Edge a, Edge b)
{
    if (a.w == b.w)
    {
        if (a.u == b.u)
            return a.v < b.v;
        return a.u < b.u;
    }
    return a.w > b.w;
}

int find(int idx)
{
    if (idx < 0 || parent[idx] == idx)
        return idx;
    else
        return parent[idx] = find(parent[idx]);
}

void uni(int a, int b)
{
    int apar = find(a);
    int bpar = find(b);
    if (apar < 0)
        parent[bpar] = apar;
    else
        parent[apar] = bpar;
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);

    // init parents
    for (int i = 0; i < N; i++)
        parent[i] = i;
    for (int i = 0; i < K; i++)
    {
        int idx;
        scanf("%d", &idx);
        parent[idx] = -idx;
    }
    // inputs
    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        Edge e(u, v, w);
        E.push_back(e);
    }
    sort(E.begin(), E.end(), comp);

    ll sum = 0;

    for (int i = 0; i < N - K;)
    {
        Edge e = E.back();
        E.pop_back();
        // printf("%d %d %d / %d\n",e.u,e.v,e.w, sum);
        int upar = find(e.u);
        int vpar = find(e.v);
        if ((upar < 0 && vpar < 0)|| upar == vpar)
            continue;
        uni(e.u, e.v);
        i++;
        sum += e.w;
    }

    printf("%lld\n", sum);

    return 0;
}