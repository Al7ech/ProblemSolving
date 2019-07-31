#include <stdio.h>
#include <set>

using namespace std;
typedef long long ll;

int K, N;
int A[100];
set<int> s;
int main(void)
{
    scanf("%d%d", &K, &N);
    for (int i = 0; i < K; i++)
    {
        scanf("%d", A + i);
        s.insert((ll)A[i]);
    }
    ll t;

    for (int i = 0; i < N; i++)
    {
        t = *s.begin();
        // printf("%lld\n", t);
        s.erase(t);

        for (int j = 0; j < K; j++)
        {
            if (t * A[j] < ((ll)1 << 31))
            {
                s.insert(t * A[j]);
                if (s.size() > N)
                    s.erase(*s.rbegin());
            }
        }
    }
    printf("%lld\n", t);

    return 0;
}