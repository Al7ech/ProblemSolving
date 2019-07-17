#include <stdio.h>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, M, a, b;
int cordX[300005], cordY[300005];
ll sumX[300005], sumY[300005];
int X[300005], Y[300005];

int main(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", cordX + i, X + i);
        sumX[i + 1] = (ll)X[i] + sumX[i];
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", cordY + i, Y + i);
        sumY[i + 1] = (ll)Y[i] + sumY[i];
    }
    scanf("%d %d", &a, &b);

    ll ans = 0;

    for (int i = 0; i < N; i++)
    {
        int f = lower_bound(cordY, cordY + M, cordX[i] + a) - cordY;
        int l = upper_bound(cordY, cordY + M, cordX[i] + b) - cordY - 1;
        ans += (ll)X[i] * (sumY[l + 1] - sumY[f]);
    }
    printf("%lld\n",ans);

    return 0;
}