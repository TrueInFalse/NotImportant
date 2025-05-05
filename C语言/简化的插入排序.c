#include<stdio.h>
int main()
{
    int N,x,i,t;
    scanf("%d",&N);
    if(N!=0){
    	int a[N+1];
    	for(i=1;i<N+1;i++){
        	scanf("%d",&a[i]);
    	}
    	scanf("%d",&x);
    	a[0]=x;
    	for(i=0;a[i]>a[i+1];i++){
        	t=a[i+1];
        	a[i+1]=a[i];
        	a[i]=t;
    	}
    	for(i=0;i<N+1;i++){
        	printf("%d ",a[i]);
    	}
	}
	if(N==0){
		scanf("%d",&x);
		printf("%d",x);
	}
    return 0;
}
