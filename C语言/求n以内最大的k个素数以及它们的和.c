#include <stdio.h>
int main()
{
    int n,k,i,j,q=0,sum=0;
    scanf("%d %d",&n,&k);
    i=n;
    for(i;i>=2;i--)
    {
        int isprime=1;
        for(j=2;j<i-1;j++)
        {
            if(i%j==0){
                    isprime=0;
                    break;
                    }
        }
        if(isprime==1){
            sum+=i;
            if(q==0)printf("%d",i);
            else printf("+%d",i);
            q++;
        }
        if(q>=k||i==2){
            printf("=%d",sum);
            break;
        }
    }
return 0;
}
