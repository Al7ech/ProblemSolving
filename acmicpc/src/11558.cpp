#include<stdio.h>

int p[10500];

int main(void)
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",&p[i+1]);
		int idx = 1;
		int cnt=0;
		bool check[10500]={0,};
		while(1)
		{
			if(idx == n)
			{
				printf("%d\n",cnt);
				break;
			}
			if(check[idx])
			{
				printf("0\n");
				break;
			}
			cnt++;
			check[idx]=1;
			idx = p[idx];
		}
	}
	return 0;
}
