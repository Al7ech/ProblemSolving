#include <stdio.h>
#include <math.h>
#include <vector>

typedef long long ll;

using namespace std;

int N, M, K;
int bp;
int A[4000000];
vector<ll> tree;

ll init(int node, int s, int e)
{
    if (s == e)
        return tree[node] = A[s];
    int m = (s + e) / 2;
    return tree[node] = init(node * 2, s, m) + init(node * 2 + 1, m + 1, e);
}
void update(int node, int s, int e, int idx, int diff)
{
    if (idx < s || e < idx)
        return;
    tree[node] += diff;
    if (s != e)
    {
        int m = (s + e) / 2;
        update(node * 2, s, m, idx, diff);
        update(node * 2 + 1, m + 1, e, idx, diff);
    }
}
ll sum(int node, int s, int e, int a, int b)
{
    if (e < a || b < s)
        return 0;
    if (a <= s && e <= b)
        return tree[node];
    int m = (s + e) / 2;
    return sum(node * 2, s, m, a, b) + sum(node * 2 + 1, m + 1, e, a, b);
}

int main(void)
{
    scanf("%d%d%d", &N, &M, &K);

    for (int i = 0; i < N; i++)
        scanf("%d", A + i);

    tree = vector<ll>(N * 4, 0);

    init(1, 0, N - 1);

    for (int i = 0; i < M + K; i++)
    {
        int T, x, y;
        scanf("%d%d%d", &T, &x, &y);
        if (T == 1)
        {
            x--;
            int diff = y - A[x];
            A[x] = y;
            update(1, 0, N - 1, x, diff);
        }
        else
            printf("%lld\n", sum(1, 0, N - 1, x - 1, y - 1));
    }

    return 0;
}