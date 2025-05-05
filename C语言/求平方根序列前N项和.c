#include<stdio.h>
#include<math.h>
int main()
{
    double sum=0,n;
    int t,i=1;
    scanf("%lf",&n);
    t=n;
    for(i=1;i<=t;i++){
        sum=pow(i*1.0,1.0/2)+sum;
    }
    printf("%.2lf",sum);
    return 0;
}
