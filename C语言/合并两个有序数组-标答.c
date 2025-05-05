#include <stdio.h>
int main(){
	int m,n,i,j,k,t=0,num;
		scanf("%d",&m);
	int c[m];
	for(i=0;i<m;i++){
		scanf("%d",&c[i]);}
		scanf("%d",&n);
	int b[n];
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);}
//一般代码，定义并输入，这里用变量来定义数组的大小；
	int a[m+n];
	for(i=0;i<m;i++){
		a[i]=c[i];}
	for(i=0;i<n;i++){
		a[m+i]=b[i];
		}//把两个数组组合并成一个数组 ~ 

	for(i=0;i<m+n-1-t;i++){//减一保证j能存在 t=0一开始 
		for(j=i+1;j<m+n-t;j++){ 
			if(a[i]==a[j]){//如果咱看的这一项等于要看的下一项，就进入循环 
				for(k=j;k<m+n-t;k++){
					a[k]=a[k+1];//要看的下一项之后的所有项向 前移一项 
				}				//就是把要看的下一项（i+1） 挤掉 
				t++;
			}
			//否则咱就 i++; 
		}	
	}//把重复的合成一个，整体向前移动位置 ~ 
	for(i=0;i<m+n-t;i++){
		for(j=i+1;j<m+n-t;j++){
			if(a[i]>a[j]){
				num=a[i];
				a[i]=a[j];
				a[j]=num;
			}
			//否则咱就 j++ 看下一项 
		}
	}//通过循环调整大小顺序排序
	for(i=0;i<m+n-t-1;i++){
		printf("%d ",a[i]);
	}
	printf("%d",a[m+n-t-1]);//分类输出，确保最后一个字符没有空格
	return 0;
}
