/*
#include <stdio.h>

int M=-1;
int sum;

void max(int x)
{
	if(x>M) M=x;
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		sum+=tmp;
		max(tmp);
	}
	printf("%f",(float)sum/(M*n));
	return 0;
}
//*/
#include<stdio.h>

int M=-1;
float val[1000];
float sum;

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%f",&val[i]);
		if(val[i]>M) M=val[i];
	}
	for(int i=0;i<n;i++)
	{
		val[i] = val[i]/M*100;
		sum+=val[i];
	}
	printf("%f\n",sum/n);
}
