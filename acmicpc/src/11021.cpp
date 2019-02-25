#include <stdio.h>

int tc;
int a,b;

int main(void)
{
	scanf("%d",&tc);
	for(int i=1;tc--;i++)
	{
		scanf("%d %d",&a,&b);
		printf("Case #%d: %d\n",i,a+b);
	}
	return 0;
}
