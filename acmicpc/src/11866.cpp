#include<stdio.h>

bool p[1001];

int main(void)
{
	int n,m;
	scanf("%d %d",&n,&m);
	int idx=0;
	printf("<");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(p[idx+1]) j--;
			idx=(idx+1)%n;
		}
		p[idx+n*(!idx)]=1;
		printf("%d",idx+n*(!idx));
		if(i!=n-1)
			printf(", ");
		else printf(">");
	}
	return 0;
}
