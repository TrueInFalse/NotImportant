#include<stdio.h>
int main()
{
    int a[10],b[10],flag=0;
    for(int i=0;i<10;i++){
        scanf("%d",&a[i]);
    }//数组赋值 
    for(int i=0;i<10;i++){
        int count=0;
        for(int j=i;j<10;j++){
            if(a[j]==a[i]) count++;//确定某个数在数组中出现的次数 ，在整个数组中走一圈看看有没有相等的 
        }
        b[i]=count;// 
        flag++;
    }
    int max=b[0],x=0;
    for(int i=0;i<flag;i++){//找出b数组中最大值为哪一项 
        if(b[i]>max){
            max=b[i];
            x=i;//x用来确定最大值所在b数组中的项数 
        }
        //否则直接i++
    }
    printf("%d出现了%d次",a[x],max);
    return 0;
}
