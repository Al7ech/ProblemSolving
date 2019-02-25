#include <stdio.h>
#define MAX 1234567

int max(int a,int b){
    if(a>b)
        return a;
    return b;
}
int len[MAX];

int main(void){

    int N,M;
    int maxlen = 0;
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        scanf("%d",&len[i]);
        maxlen = max(maxlen,len[i]);
    }
    int m = 0,Max = maxlen;
    int mid;
    while(m<Max){
        mid = (m+Max)/2;
        int comp_m=0;
        for(int i=0;i<N;i++) comp_m+=max(0,len[i]-mid);

        if(comp_m>M) Max=mid+1;
        else if(comp_m<M) m=mid+1;
        printf("%d\n",mid);
    }
    printf("%d\n",mid);



    return 0;
}