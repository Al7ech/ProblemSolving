#include <stdio.h>

int min(int a,int b)
{
    if(a>b)
        return b;
    return a;
}

int main(void)
{
    int N,k;

    scanf("%d\n%d",&N,&k);
    int m=1,M = min(1e+9,N*N);

    while(m+1<M)
    {
        int mid = (m+M+1)/2;
        int cnt=0;
        for(int i=1;i<=N;i++) cnt+=min(N,mid/i-(mid%i==0));
        printf("%d %d %d // %d %d\n",m,mid,M,cnt+1,k);
        if(cnt+1==k) break;
        if(cnt+1>k) M=mid-1;
        else m=mid;
    }
    int pre_ans = (m+M+1)/2;
    while(1)
    {
        bool flag=false;
        for(int i=1;i<N;i++){
            if(pre_ans%i==0&&pre_ans/i<=N){
                flag = true;
                break;
            }
        }
        if(flag) break;
        pre_ans++;
    }
    printf("%d\n",pre_ans);

    return 0;
}