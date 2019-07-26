#include <stdio.h>
#include <vector>

typedef long long ll;
using namespace std;

ll ans;
int N, Q;
int arr[100001];
vector<ll> t;

ll init(int node, int s, int e)
{
    if (s == e)
        return t[node] = arr[s];

    int m = (s + e) / 2;

    return t[node] = init(node * 2, s, m) + init(node * 2 + 1, m + 1, e);
}

ll query(int node, int s, int e, int a, int b)
{
    if (a <= s && e <= b)
        return t[node];
    if (e < a || b < s)
        return 0;

    int m = (s + e) / 2;
    return query(node * 2, s, m, a, b) + query(node * 2 + 1, m + 1, e, a, b);
}

void update(int node, int s, int e, int idx, int diff)
{
    if (idx < s || e < idx)
        return;
    t[node] += diff;
    if (s == e)
        return;
    int m = (s + e) / 2;
    update(node * 2, s, m, idx, diff);
    update(node * 2 + 1, m + 1, e, idx, diff);
}

int main(void)
{
    scanf("%d%d", &N, &Q);
    t = vector<ll>(N * 4, 0);
    for (int i = 0; i < N; i++)
        scanf("%d", arr + i);

    init(1, 0, N - 1);

    for (int i = 0; i < Q; i++)
    {
        int x, y, a, b;
        scanf("%d%d%d%d", &x, &y, &a, &b);
        x--, y--, a--;

        printf("%lld\n", query(1, 0, N - 1, x, y));
        update(1, 0, N - 1, a, b - arr[a]);
        arr[a] = b;
    }
}