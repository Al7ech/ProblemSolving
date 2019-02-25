#include<stdio.h>

int main(void)
{
	int a,b,n;
	int x,y;
	scanf("%d %d %d",&a,&b,&n);
	for(int i=-1;i<n;i++)
	{
		x = a/b;
		y = a%b;
		a = y;
		a*=10;
	}
	printf("%d",x);
	return 0;
}
