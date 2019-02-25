#include <stdio.h>

int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
//sun=0 mon=1
int main(void)
{
	int m,d;
	int cnt=0;
	scanf("%d %d",&m,&d);
	for(int i=0;i<m-1;i++)
	{
		cnt+=day[i];
	}
	cnt+=d;
	cnt%=7;
	if(cnt==0) printf("SUN");
	else if(cnt==1) printf("MON");
	else if(cnt==2) printf("TUE");
	else if(cnt==3) printf("WED");
	else if(cnt==4) printf("THU");
	else if(cnt==5) printf("FRI");
	else if(cnt==6) printf("SAT");
	return 0;
}
