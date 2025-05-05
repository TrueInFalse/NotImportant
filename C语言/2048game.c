#include<stdio.h>
int main()
{
    int a[4],i,j,k;
    for(i=0;i<4;i++)
        scanf("%d",&a[i]);
    for(k=0;k<3;k++){
        for(i=0;i<3;i++){
            if(a[i]==0){
                for(j=i;j<4;j++){
                    a[j]=a[j+1];
                }
                a[3]=0;
            }
        }
    }
    for(i=0;i<3;i++){
        if((a[i]==a[i+1])&&(a[i]!=0)){
            a[i]+=a[i+1];
            for(j=i+1;j<4;j++){
                a[j]=a[j+1];
            }
            a[3]=0;
        }
    }
    for(i=0;i<4;i++){
        if(i==3)
            printf("%d\n",a[i]);
        else
            printf("%d ",a[i]);
    }
    return 0;
}