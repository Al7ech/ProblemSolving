#include<stdio.h>

int num[20];

int main(void)
{
	num[1] = 1;
	num[2] = 2;
	num[3] = 4;
	for(int i=4;i<12;i++) num[i] = num[i-1]+num[i-2]+num[i-3];
	int tc,n;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d",&n);
		printf("%d\n",num[n]);
	}
	return 0;
}
