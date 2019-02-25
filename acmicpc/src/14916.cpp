#include<stdio.h>

int main(void)
{
	int n;
	int cnt=0;
	scanf("%d",&n);
	while(n%5)
	{
		n-=2;
		cnt++;
		if(n<0)
		{
			puts("-1");
			return 0;
		}
	}
	cnt+=n/5;
	printf("%d",cnt);
	return 0;
}
