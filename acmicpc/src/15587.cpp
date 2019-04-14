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
#define MAXN 100005

int N, K;
vector<int> V[MAXN];
bool visited[MAXN];
int level[MAXN];

void getLevel(int idx, int curlevel)
{
    level[idx] = curlevel;

    for (int next : V[idx])
        if (level[next] == -1)
            getLevel(next, curlevel + 1);
}

pair<int, int> getMin(int idx) // first = ans, second = closest leaf's level
{
    int minlevel = 987654321;
    int sum = 0;

    visited[idx] = true;
    for (int next : V[idx])
    {
        if (!visited[next])
        {
            pair<int, int> res = getMin(next);
            minlevel = min(minlevel, res.second);
            sum += res.first;
        }
    }
    if (minlevel == 987654321)
        return make_pair(1, level[idx]);
    if (minlevel - level[idx] <= level[idx])
        return make_pair(1, minlevel);
    return make_pair(sum, minlevel);
}

int main()
{
    memset(level, -1, sizeof(level));
    scanf("%d %d", &N, &K);
    K--;
    for (int i = 0; i < N - 1; i++)
    {
        int s, e;
        scanf("%d %d", &s, &e);
        V[s - 1].push_back(e - 1);
        V[e - 1].push_back(s - 1);
    }
    getLevel(K, 0);
    printf("%d\n", getMin(K).first);

    return 0;
}