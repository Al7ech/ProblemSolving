#include<stdio.h>

int k;
int cnt;
int route[2000000][2];

void hanoi(int s,int d,int none,int num)
{
	if(!num) return;
	hanoi(s,none,d,num-1);
	route[cnt][0]=s;
	route[cnt++][1]=d;
	hanoi(none,d,s,num-1);
}

int main(void)
{

	scanf("%d",&k);
	hanoi(1,3,2,k);
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++) printf("%d %d\n",route[i][0],route[i][1]);
	return 0;
}
