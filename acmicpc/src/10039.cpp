#include<stdio.h>

int sum;

int main(void)
{
	int n;
	for(int i=0;i<5;i++)
	{
		scanf("%d",&n);
		if(n<40) sum+=40;
		else sum+=n;
	}
	printf("%d",sum/5);
	return 0;
}
