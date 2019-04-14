#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
typedef long long ll;

int N;

int main()
{
    scanf("%d\n", &N);

    int start = N, end = -1;

    for (int i = 0; i < N; i++)
    {
        char tmp;
        scanf("%c",&tmp);
        if(tmp == '<') end = i;
        else if (start == N) start = i;
    }
    if(end == -1 || start == N)
        printf("%d\n",N);
    else
        printf("%d\n",end-start+1+min(start,N-1-end));

    return 0;
}