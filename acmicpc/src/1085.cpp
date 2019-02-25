#include<stdio.h>

int min(int a,int b)
{
	if(a>b) return b;
	return a;
}

int main(void)
{
	int x,y,w,h;
	scanf("%d %d %d %d",&x,&y,&w,&h);
	printf("%d",min(min(x,y),min(w-x,h-y)));
	return 0;
}
