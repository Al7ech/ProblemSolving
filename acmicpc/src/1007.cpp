#include<stdio.h>
#include<math.h>

struct dot
{
	int x,y;
};
dot d[20];
int m=123456789;
int min(int a,int b)
{
	if(a>b) return b;
	return a;
}

void dfs(int cnt,bool check[],int idx)
{
	if(idx == 19)
	{
		for(int i=0;i<20;i++)printf("%d",check[i]);
		puts("");
		int x=0,y=0;
		for(int i=0;i<20;i++)
		{
			if(check[i]) {x+=d[i].x;y+=d[i].y;}
			else {x-=d[i].x;y-=d[i].y;}
		}
		printf("%d %d\n",x,y);
		m = min(m,x*x+y*y);
	}
	if(cnt<10)
	{
		check[idx] = true;
		dfs(cnt+1,check,idx+1);
	}
	check[idx] = false;
	dfs(cnt,check,idx+1);

}

int main(void)
{
	int tc;
	m=123456789;
	scanf("%d",&tc);
	while(tc--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d %d",&d[i].x,&d[i].y);
		bool c[20]={0,};
		dfs(0,c,0);
		printf("%.6lf", sqrt(m));
	}
	return 0;
}
