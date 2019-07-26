#include <stdio.h>
#include <vector>

typedef long long ll;
using namespace std;

int N;
int M[500005];
ll ans;
vector<int> t;

ll query(int node, int s, int e, int a, int b)
{
    // printf("Q : %d %d %d %d %d\n",node,s,e,a,b);
    if (a > b)
        return 0;
    if (e < a || b < s)
        return 0;
    if (a <= s && e <= b)
        return t[node];

    int m = (s + e) / 2;
    return query(node * 2, s, m, a, b) + query(node * 2 + 1, m + 1, e, a, b);
}
void update(int node, int s, int e, int idx, int diff)
{
    // printf("U : %d %d %d %d %d\n",node,s,e,idx,diff);

    if (idx < s || e < idx)
        return;
    t[node] += diff;
    if(s == e)
        return;
    int m = (s + e) / 2;
    update(node * 2, s, m, idx, diff);
    update(node * 2 + 1, m + 1, e, idx, diff);
}

int main(void)
{
    scanf("%d", &N);
    t = vector<int>(4 * N, 0);
    {
        int V[1000001];

        for (int i = 0; i < N; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            V[tmp] = i;
        }
        for (int i = 0; i < N; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            M[V[tmp]] = i;
        }
    }
    for (int i = 0; i < N; i++)
    {
        ans += query(1, 0, N - 1, M[i] + 1, N - 1); // if s>e return
        update(1, 0, N - 1, M[i], +1);
    }
    printf("%lld\n",ans);
}