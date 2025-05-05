#include<stdio.h>
int main()
{
    int a,b,c,d,t=0;
    scanf("%d",&a);
    b=a+1;
    c=a+2;
    d=a+3;
    for(int i=0;i<4;i++){

        printf("%d ",a*100+b*10+c*1);
        printf("%d ",a*100+b*10+d*1);
        printf("%d ",a*100+c*10+b*1);
        printf("%d ",a*100+c*10+d*1);
        printf("%d ",a*100+d*10+b*1);
        printf("%d\n",a*100+d*10+c*1);
        t=a;
        a=b;
        b=c;
        c=d;
        d=t;
    }

    return 0;
}
