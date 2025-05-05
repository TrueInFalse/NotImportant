#include<stdio.h>
int main()
{
    int y,m,d;
    scanf("%d-%d-%d",&y,&m,&d);
    if(m==12)
        printf("还有%d天到新年",32-d);
    if(m==11)
        printf("还有%d天到新年",32-d+30);
    if(m==10)
        printf("还有%d天到新年",32-d+61);
    if(m==9)
        printf("还有%d天到新年",32-d+91);
    if(m==8)
        printf("还有%d天到新年",32-d+122);
    if(m==7)
        printf("还有%d天到新年",32-d+153);
    if(m==6)
        printf("还有%d天到新年",32-d+183);
    if(m==5)
        printf("还有%d天到新年",32-d+214);
    if(m==4)
        printf("还有%d天到新年",32-d+244);
    if(m==3)
        printf("还有%d天到新年",32-d+275);
    if(m==2)
        printf("还有%d天到新年",32-d+303);
    if(m==1)
        printf("还有%d天到新年",32-d+344);
    return 0;
}
