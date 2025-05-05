#include <stdio.h>
int main()
{
    int a,b,a1,a2,a3;
    scanf("%d %d",&a,&b);
    a1=(a/100)*60+(a-(a/100)*100);
    a2=a1+b;
    a3=(a2/60)*100+(a2-(a2/60)*60);
    printf("%03d",a3);
    return 0;
}
