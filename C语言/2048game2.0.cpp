#include<stdio.h>
int main()
{
    int a[4],flag=0;
    for(int i=0;i<4;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<4;i++){
        if(a[i]==0){
            for(int j=i;j<3;j++){
                a[j]=a[j+1];
            }
            a[3]=0;
            i=i-1;
            flag++;
        }
        if(flag==4)
            break;
    }
    for(int i=0;i<3;i++){
        if(a[i]==a[i+1] && a[i]!=0){
            a[i]=2*a[i];
            for(int j=i+1;j<4;j++){
                a[j]=a[j+1];
            }
            a[3]=0;
        }
    }
    for(int i=0;i<4;i++){
        if(i==3)
            printf("%d",a[3]);
        else
            printf("%d ",a[i]);
    }
    return 0;
}