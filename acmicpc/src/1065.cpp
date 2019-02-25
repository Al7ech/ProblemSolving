#include<stdio.h>

int n;
int cnt;

void check(int i)
{
	bool flag=1;
	int num[4];
	int x=0;
	while(1)
	{
		if(i==0) break;
		num[x++]=i%10;
		i/=10;
	}
	int val = num[1]-num[0];
	for(int j=2;j<x;j++)
	{
		if(num[j]-num[j-1]!=val)
		{
			flag=false;
			break;
		}
	}
	if (flag) cnt++;
}

int main(void)
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) check(i);
	printf("%d",cnt);
	return 0;
}
