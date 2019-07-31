#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int N, Q;
int A[100005];
vector<vector<int>> t;

void init(int node, int s, int e)
{
    if (s == e)
    {
        t[node] = vector<int>(1, A[s]);
        return;
    }

    int m = (s + e) / 2;
    t[node] = vector<int>(e - s + 1);

    init(node * 2, s, m);
    init(node * 2 + 1, m + 1, e);

    merge(t[node * 2].begin(), t[node * 2].end(), t[node * 2 + 1].begin(), t[node * 2 + 1].end(), t[node].begin());

    return;
}

int I, J, K;
int L, R, M;

int query(int node, int s, int e)
{
    if (e < I || J < s)
        return 0;

    if (I <= s && e <= J)
        return upper_bound(t[node].begin(), t[node].end(), M) - t[node].begin();

    int m = (s + e) / 2;

    return query(node * 2, s, m) + query(node * 2 + 1, m + 1, e);
}

int main(void)
{
    scanf("%d%d", &N, &Q);
    for (int i = 0; i < N; i++)
        scanf("%d", A + i);

    t = vector<vector<int>>(4 * N);
    init(1, 0, N - 1);

    for (int i = 0; i < Q; i++)
    {
        scanf("%d%d%d", &I, &J, &K);
        I--, J--;
        L = -1e9, R = 1e9;

        while (L <= R)
        {
            M = (L + R) / 2;
            if (query(1, 0, N - 1) < K)
                L = M + 1;
            else
                R = M - 1;
        }
        printf("%d\n", L);
    }

    return 0;
}