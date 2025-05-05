#include<stdio.h>
int main()
{
    int y,i=0,n=0,k;
    scanf("%d",&y);
    if(y==2100) y=2099;
    if(y<=2000||y>2100){
        printf("Invalid year!");
    }
    if(y>2000&&y<=2100){
        i=y-2000;
        n=i/4;
        if(n==0){printf("None");}
        if(n>0){
            for(k=4;k<=i;k=k+4){
                printf("%d\n",2000+k);
            }
        }
    }
    return 0;
}
