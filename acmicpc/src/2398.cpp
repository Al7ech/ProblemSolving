#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <string.h>
#include <iostream>

using namespace std;

typedef struct p
{
    int length;
    vector<int> V;

    p(int L) : length(L) { V.clear(); }
} Path;

using namespace std;

int N, M;
int C[3];
vector<int> E[1005];

Path myMin(Path a, Path b)
{
    if (a.length > b.length)
        return b;
    return a;
}

Path addPath(Path a, Path b)
{
    a.length += b.length;
    for (int i = 0; i < b.V.size(); i++)
        a.V.push_back(b.V[i]);

    return a;
}

Path dijk(Path s, Path d)
{
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    return Path(0);
}

Path get_min(int d_idx)
{
    Path sklt = dijk((d_idx + 1) % 3, (d_idx + 2) % 3);

    Path add = Path(1e+9);
    for (int i = 0; i < sklt.V.size(); i++)
        add = myMin(add, dijk(d_idx, sklt.V[i]));

    Path ret = addPath(sklt, add);

    return ret;
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", C, C + 1, C + 2);
        C[0]--, C[1]--;
        E[C[0]].push_back(C[1]);
        E[C[1]].push_back(C[0]);
    }
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", C + i);
        C[i]--;
    }

    Path ans = Path(1e+9);
    for (int i = 0; i < 3; i++)
        ans = myMin(ans, get_min(i));

    printf("%d %d\n", ans.length, (int)ans.V.size() - 1);
    for (int i = 1; i < ans.V.size(); i++)
    {
        printf("%d %d\n", ans.V[i - 1], ans.V[i]);
    }

    return 0;
}