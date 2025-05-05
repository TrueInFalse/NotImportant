#include<stdio.h>
int main()
{
    int n,m,t=0,q=0;
    scanf("%d",&n);//确定数组长度 
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);//数组赋值 
    }
    scanf("%d",&m);//确定删除数据 
    for(int i=0;i<n;i++){
        if(a[i]==m){
        	t=i;
            for(;i<n;i++){
                a[i]=a[i+1];
            }
            n--;//缩减数组长度 
            for(int i=0;i<n;i++){
                printf("%d ",a[i]);//输出删除指定数据后数组 
            }
            printf("\n");
        }
        i=t;
    }
    /*t=i;
    for(i=0;i!=t;i++){
        printf("%d ",a[i]);
    }
    for(i=t+1;i<n;i++){
        printf("%d ",a[i]);
    }*/
    return 0;
}
