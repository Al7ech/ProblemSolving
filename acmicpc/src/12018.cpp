#include<stdio.h>
#include<algorithm>

int n,m;
int point_need[100];


int main(void)
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int p,max;
		int point[100];
		scanf("%d %d",&p,&max);
		for(int j=0;j<p;j++) scanf("%d",&point[j]);
		std::sort(point,point+p);
		std::reverse(point,point+p);
		std::fill(point+p,point+100,1);
		point_need[i]=point[max-1];
	}
	std::sort(point_need,point_need+n);
	int cnt=0;
	for(int i=0;m-point_need[i]>=0&&i<n;i++)
	{
		m-=point_need[i];
		cnt++;
	}
	printf("%d",cnt);
	return 0;
}

/*
36 36 36 (25) 25 1
30 24 25 (20) 20
36 36 36 (36) 36 36 36
3 7 0 (1)!! 0 0
27 26 15 (14) 14 8
*/
