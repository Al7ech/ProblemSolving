#include<stdio.h>
int cnt;

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=0;;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(++cnt==n)
			{
				if(i%2)
					printf("%d/%d",j+1,i-j+1);
				else
					printf("%d/%d",i-j+1,j+1);
				return 0;
			}
		}
	}
	return 0;
}
