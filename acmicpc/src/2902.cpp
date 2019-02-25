#include<stdio.h>
#include<string.h>

char s[100];


int main(void)
{
	scanf("%s",s);
	for(int i=0;i<strlen(s);i++)
	{
		if('A'<=s[i] && s[i] <='Z') printf("%c",s[i]);
	}
	return 0;
}
