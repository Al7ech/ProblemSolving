#include <stdio.h>
#include <queue>

using namespace std;
typedef long long ll;

int K, N;
int A[100];
priority_queue<ll> pq;

int main(void)
{
    scanf("%d%d", &K, &N);
    for (int i = 0; i < K; i++)
    {
        scanf("%d", A + i);
        pq.push(-(ll)A[i]);
    }
    ll t;
    for (int i = 0; i < N; i++)
    {
        t = -pq.top();
        pq.pop();
        while (-t == pq.top())
            pq.pop();

        for (int j = 0; j < K; j++)
            pq.push(-t * A[j]);
    }
    printf("%lld\n", t);

    return 0;
}