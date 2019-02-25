#include<stdio.h>

int maxval = 1;

int  main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1;;i++)
	{
		if(n<=maxval)
		{
			printf("%d",i);
			return 0;
		}
		maxval+=6*i;
	}
	return 0;
}
