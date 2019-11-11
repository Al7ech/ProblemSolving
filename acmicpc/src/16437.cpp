#include <algorithm>
#include <stdio.h>
#include <vector>
typedef long long ll;
using namespace std;

int N;
int t[130000], a[130000], p[130000];
vector<int> E[130000];

ll dfs(int idx)
{
    ll ans = 0;
    for (int V : E[idx])
    {
        ans += dfs(V);
    }
    if (t[idx])
        ans += a[idx];
    else
        ans -= a[idx];
    return max(ans, (ll)0);
}

int main(void)
{
    scanf("%d\n", &N);

    for (int i = 2; i <= N; i++)
    {
        scanf("%c %d %d\n", t + i, a + i, p + i);
        t[i] = (t[i] == 'S') ? 1 : 0;
        E[p[i]].push_back(i);
    }
    printf("%lld", dfs(1));

    return 0;
}