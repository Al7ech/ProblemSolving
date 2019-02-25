#include <stdio.h>

int n;
int main(void)
{
	scanf("%d",&n);
	int sum=0;
	for(int i=0;i<n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		sum+=tmp;
	}
	if(sum*2<n)
		printf("Junhee is not cute!");
	else
		printf("Junhee is cute!");
	return 0;
}
