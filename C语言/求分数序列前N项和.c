#include<stdio.h>
int main()
{
    int N,i;
    double sum=0,n,t,m=2.0,z=1.0;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        n=m/z;
        sum=sum+n;
        t=z;
        z=m;
        m=t+z;
    }
    printf("%.2lf",sum);
    return 0;
}
