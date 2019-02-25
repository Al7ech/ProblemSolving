#include <stdio.h>

int cnt[2];

int fibonacci(int n) {
    if (n==0) {
        cnt[0]++;
        return 0;
    } else if (n==1) {
        cnt[1]++;
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int t;

int main()
{
	scanf("%d",&t);
	for(int tc=0;tc<t;tc++)
	{
		cnt[0]=cnt[1]=0;
		int n;
		scanf("%d",&n);
		fibonacci(n);
		printf("%d %d\n",cnt[0],cnt[1]);
	}
	return 0;
}
