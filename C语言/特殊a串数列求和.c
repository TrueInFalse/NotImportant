#include<stdio.h>
int main()
{
    int s=0,a,n,i=0,t;
    scanf("%d %d",&a,&n);
    t=a;
    for(i=0;i<n;i++){
        s=s+a;
        a=a*10+t;
    }
    printf("s = %d",s);
    return 0;
}
