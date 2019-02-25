#include<stdio.h>
#include<string.h>

char s[500];


int main(void)
{
	while(1)
	{
		gets(s);
		int len = strlen(s);
		if(strcmp(s,"END")==0)
			break;
		for(int i=len-1;i>=0;i--) printf("%c",s[i]);
		puts("");
	}
	return 0;
}
