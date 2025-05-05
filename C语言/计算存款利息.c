#include <stdio.h>
#include <math.h>
int main()
{
    float money,rate,year,interest,ret;
    scanf("%f  %f  %f",&money,&year,&rate);
    ret=pow(1+rate,year);
    interest=ret*money-money;
    printf("interest=%.2f",interest);
    return 0;
}
