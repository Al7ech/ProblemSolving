#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int A[100005];
vector<vector<int>> t;

vector<int> init(int node, int s, int e)
{
    // printf("%d %d %d\n", node, s, e);

    if (s == e)
        return t[node] = vector<int>(1, A[s]);

    int m = (s + e) / 2;
    t[node] = vector<int>(e - s + 1);

    vector<int> l = init(node * 2, s, m);
    vector<int> r = init(node * 2 + 1, m + 1, e);

    merge(l.begin(), l.end(), r.begin(), r.end(), t[node].begin());

    return t[node];
}

int I, J, K;
vector<int> query(int node, int s, int e)
{
    if (e < I || J < s)
        return vector<int>(0);

    if (I <= s && e <= J)
        return t[node];

    int m = (s + e) / 2;
    vector<int> l = query(node * 2, s, m), r = query(node * 2 + 1, m + 1, e);
    vector<int> tmp(l.size() + r.size());

    merge(l.begin(), l.end(), r.begin(), r.end(), tmp.begin());

    // printf("\n%d %d %d\n", node, s, e);

    // for (int i : vector<int>(tmp.begin(), tmp.end()))
    //     printf("%d ", i);
    // puts(" }");

    return vector<int>(tmp.begin(), min(tmp.end(), tmp.begin() + e - s + 1));
}

int main(void)
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", A + i);

    t = vector<vector<int>>(4 * N);
    init(1, 0, N - 1);

    for (int i = 0; i < M; i++)
    {
        scanf("%d%d%d", &I, &J, &K);
        I--, J--;

        printf("%d\n", query(1, 0, N - 1)[K - 1]);
    }

    return 0;
}