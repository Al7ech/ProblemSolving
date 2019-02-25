#include<stdio.h>

int sum;
int val[1000];

int main(void)
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n;
		sum=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&val[i]);
			sum+=val[i];
		}
		int cnt=0;
		for(int i=0;i<n;i++) if(val[i]*n > sum) cnt++;
		printf("%.3f%%\n",(float)(cnt*100)/n);
	}
	return 0;
}
