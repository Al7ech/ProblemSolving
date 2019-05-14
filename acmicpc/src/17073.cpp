#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <iostream>

using namespace std;

vector<int> E[500005];
bool visit[500005] = {
    0,
};

int N, W;

int getLN(int idx)
{
    int sum = 0;
    visit[idx] = 1;
    for (int next : E[idx])
    {
        if (!visit[next])
            sum += getLN(next);
    }
    if (!sum)
        return 1;
    return sum;
}

int main()
{
    scanf("%d %d", &N, &W);

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b--;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    int ln = getLN(0);

    printf("%lf", (double)W / ln);

    return 0;
}