#include<stdio.h>

int num[10];
char n[10];

int max(int a,int b)
{
	if(b>a) return b;
	return a;
}
int m = -1;

int main(void)
{
	scanf("%s",n);
	for(int i=0;n[i];i++)
	{
		num[n[i]-'0']++;
	}
	for(int i=0;i<10;i++)
	{
		if(i==6||i==9)
			continue;
		m = max(m,num[i]);
	}
	printf("%d",max(((num[6]+num[9]+1)/2),m));
	return 0;
}
