#include<stdio.h>
int main()
{
    int n,m,flag=0,i,j,k;
    scanf("%d",&n);
    int a[n];//数组长度 
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);//数组赋值 
    }
    scanf("%d",&m);//要删除的数据 
    for(i=0;i<n-flag;i++){
            if(a[i]==m){
                for(j=i;j<n-1-flag;j++){//从i项开始，之后的每一项数据前进一个位置 
                    a[j]=a[j+1];//定义新数组 
                }
                flag++;//缩减数组长度 
                for(k=0;k<n-flag;k++){
                    printf("%d ",a[k]);//输出新数组 
                }
                printf("\n");//末尾换行 
                i=i-1;
            }
    }
    if(flag==0){//另一种情况---没有要删除的数据 
        for(i=0;i<n;i++){
        	printf("%d ",a[i]);
    	}	
    //	printf("\n");
    }
    return 0;
}
