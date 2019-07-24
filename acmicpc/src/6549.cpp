#include <stdio.h>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, H[100005];

ll get_ans(int s, int e)
{
    if (s == e)
        return H[s];

    int m = (s + e) / 2;

    ll ret = max(get_ans(s, m), get_ans(m + 1, e));

    int l = m, r = m + 1;
    int height = min(H[l],H[r]);
    ret = max(ret,(ll)height * 2);

    while (s < l && r < e)
    {
        if(H[l-1] < H[r+1])
        {
            r++;
            height = min(height, H[r]);
        }
        else
        {
            l--;
            height = min(height, H[l]);
        }
        ret = max(ret, (ll)(r-l + 1) * height);
    }
    while(s != l)
    {
        l--;
        height = min(height, H[l]);
        ret = max(ret, (ll)(r-l + 1) * height);
    }
    while(e != r)
    {
        r++;
        height = min(height, H[r]);
        ret = max(ret, (ll)(r-l + 1) * height);
    }

    return ret;
}

int main(void)
{
    while (1)
    {
        scanf("%d", &N);
        if (N == 0)
            break;
        for (int i = 0; i < N; i++)
            scanf("%d", H + i);

        printf("%lld\n", get_ans(0, N - 1));
    }
    return 0;
}