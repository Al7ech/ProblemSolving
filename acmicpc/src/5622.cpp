#include<stdio.h>

char s[20];
int sum;

int main(void)
{
	scanf("%s",s);
	for(int i=0;s[i];i++)
	{
		sum+=(s[i]-'A')/3+3;
		if(s[i] == 'S'||s[i] == 'V'||s[i] == 'Y'||s[i] == 'Z')
		{
			sum--;
		}
	}
	printf("%d",sum);
	return 0;
}
