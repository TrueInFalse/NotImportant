#include<stdio.h>
int main()
{
	
  	int n,a[10],i,min,max,min1=0,max1=0,t;
  	
  	scanf("%d",&n);
  	
	for(i=0;i<n;i++){
    	scanf("%d",&a[i]);
    	//getchar();
  		}
  		
  	max=a[0];
  	
  	min=a[0];
  	
  	for(i=1;i<n;i++){
    	if(max<a[i]){
        	max1=i;
        	max=a[i];
    	}
    	if(min>a[i]){
        	min1=i;
        	min=a[i];
    	}
  	}
  	t=a[0];
  	
  	a[0]=a[min1];
  	
  	a[min1]=t;
  	
  	if(max1==0) max1=min1;
  	
  	t=a[n-1];
  	
  	a[n-1]=a[max1];
  	
  	a[max1]=t;
  	
	for(i=0;i<n;i++){
    	printf("%d ",a[i]);
  		}
  	return 0;
}

