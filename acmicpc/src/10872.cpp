#include <stdio.h>

int n;
int main(void)
{
	scanf("%d",&n);
	int sum=1;
	for(int i=1;i<=n;i++) sum*=i;
	printf("%d\n",sum);
	return 0;
}
