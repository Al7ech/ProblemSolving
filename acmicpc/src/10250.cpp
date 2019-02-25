#include<stdio.h>

int main(void)
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int w,h,n;
		scanf("%d %d %d",&w,&h,&n);
		printf("%d",n%w+w*(!(n%w)));
		if((n-1)/w+1<10) printf("0");
		printf("%d",(n-1)/w+1);
		puts("");
	}
	return 0;
}
