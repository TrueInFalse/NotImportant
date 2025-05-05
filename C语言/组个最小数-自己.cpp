#include<stdio.h>
#include<math.h>
int main()
{
    int a[10];
    int sum=0,S=0;
    for(int i=0;i<10;i++){
        scanf("%d",&a[i]);
        sum=sum+a[i];
    }
    int b[sum];
    for(int i=1;i<10;i++){
        if(a[i]!=0){
            b[0]=i;
            a[i]--;
            break;
        }
    }
    for(int i=1;i<10;i++){
        int j=1;
        if(a[0]!=0){
            b[i]=0;
            a[0]--;
        }else{
            while(j<sum){
                if(a[j]!=0){
                    b[i]=j;
                    a[j]--;
                }     
                j++;
                break;
            }
        }
    }
    for(int i=0;i<sum;i++){
        S=S+b[i]*pow(10.0,(sum-1-i)*1.0);
    }
    printf("%d",S);
    return 0;
}