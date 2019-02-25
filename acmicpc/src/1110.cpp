#include <stdio.h>

int next_val(int x)
{
	int a = x/10;
	int b = x%10;
	return b*10+(a+b)%10;
}

int main(void)
{
	int n;
	scanf("%d",&n);
	int tmp = n;
	int cnt=0;
	do
	{
		tmp = next_val(tmp);
		cnt++;
	}while(tmp!=n);
	printf("%d\n",cnt);
}
