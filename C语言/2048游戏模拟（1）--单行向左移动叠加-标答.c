#include<stdio.h>
int main()
{
    int a[4],i,j,k;
    for(i=0;i<4;i++)
        scanf("%d",&a[i]);
    for(k=0;k<3;k++)//重复三次 怕连续三个均为0
    {
        for(i=0;i<3;i++)
        {
            if(a[i]==0)//当该格为空的时候
            {
                for(j=i;j<4;j++)//所有往左移动一格子
                {
                    a[j]=a[j+1];
                }
                a[3]=0;//补0
            }
        }
    }
    for(i=0;i<3;i++)
    {
        if((a[i]==a[i+1])&&(a[i]!=0))//如果前后相等
        {
            a[i]+=a[i+1];
            for(j=i+1;j<4;j++)
            {
                a[j]=a[j+1];//右边的往左移动
            }
            a[3]=0;
        }
    }
    for(i=0;i<4;i++)
    {
        if(i==3)
            printf("%d\n",a[i]);
        else
            printf("%d ",a[i]);
    }
    return 0;
}