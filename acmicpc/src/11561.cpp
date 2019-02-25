#include<stdio.h>
#include<math.h>

int main(void)
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		long long n;
		scanf("%lld",&n);
		printf("%lld\n",(long long)(floor(sqrt(2*n+0.25)-0.5)));
	}
	return 0;
}
