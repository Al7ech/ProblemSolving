#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> V;
int farest_idx[1005];

int getDist(pair<int, int> a, pair<int, int> b)
{
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main(void)
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        V.push_back(make_pair(x, y));
    }

    if (N == 1)
    {
        printf("%lf %lf\n", (double)V[0].first, (double)V[0].second);
        return 0;
    }

    int ans_idx = -1;
    int min_dir = 1e+9;
    for (int i = 0; i < N; i++)
    {
        int f_idx = i;
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue;

            if (f_idx == i || getDist(V[i], V[f_idx]) < getDist(V[i], V[j]))
                f_idx = j;
        }
        if (ans_idx == -1 || getDist(V[i], V[f_idx]) < min_dir)
        {
            ans_idx = i;
            min_dir = getDist(V[i], V[f_idx]);
        }
    }
    printf("%lf %lf\n", (double)V[ans_idx].first, (double)V[ans_idx].second);

    return 0;
}