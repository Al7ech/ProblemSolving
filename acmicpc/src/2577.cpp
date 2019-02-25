#include <stdio.h>

int cnt[10];

int main(void)
{
	int a,b,c;
	scanf("%d\n%d\n%d",&a,&b,&c);
	int mul = a*b*c;

	while(mul)
	{
		cnt[mul%10]++;
		mul/=10;
	}
	for(int i=0;i<10;i++) printf("%d\n",cnt[i]);

}
