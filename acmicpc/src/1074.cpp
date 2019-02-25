#include<stdio.h>
#include <math.h>

int ans(int n,int r,int c)
{
	if(!n) return 0;
	int area;
	if(r<pow(2,n-1))
	{
		if(c<pow(2,n-1)) return ans(n-1,r,c);
		return ans(n-1,r,c-pow(2,n-1))+pow(2,2*n-2);
	}
	else
	{
		if(c<pow(2,n-1)) return ans(n-1,r-pow(2,n-1),c)+2*pow(pow(2,n-1),2);
		return ans(n-1,r-pow(2,n-1),c-pow(2,n-1))+3*pow(pow(2,n-1),2);
	}


}

int main(void)
{
	int n,r,c;
	scanf("%d %d %d",&n,&r,&c);
	printf("%d",ans(n,r,c));
	return 0;
}
