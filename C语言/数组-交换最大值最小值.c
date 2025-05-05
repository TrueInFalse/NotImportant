#include<stdio.h>
int main()
{
    int N;
    int zu[N];
    int i;
    int max;
    int min;
    int t;
    int max1=0;
    int min1=0;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&zu[i]);
    }
    min=zu[0];
    max=zu[0];
    for(i=1;i<N;i++){
        if(max<zu[i]){
            max=zu[i];
            max1=i;
        }
        if(min>zu[i]){
            min=zu[i];
            min1=i;
        }
    }
    if(max1!=0){
		t=zu[0];
		zu[0]=min;
		zu[min1]=t;
		t=zu[N-1];
		zu[N-1]=max;
		zu[max1]=t;
	}else{
		max1=min1;
		t=zu[0];
		zu[0]=min;
		zu[min1]=t;
		t=zu[N-1];
		zu[N-1]=max;
		zu[max1]=t;
	}
	for(i=0;i<N;i++){
		printf("%d ",zu[i]);
	}
    return 0;
}
