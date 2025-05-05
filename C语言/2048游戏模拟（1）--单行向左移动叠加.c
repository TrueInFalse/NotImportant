#include<stdio.h>
int main()
{
    int a[4];
    for(int i=0;i<4;i++){
        scanf("%d",&a[i]);
    }
    int b[4];
	/*for(int i=0;i<3;i++){
		if(a[i]==0){
			for(int j=i;j<4;j++){
				a[j]=a[j+1];
			}
			a[3]=0;
		}
	}*/
	
    for(int i=0;i<3;i++){
        printf("%d ",b[i]);
    }
    printf("%d",b[3]);
    return 0;
}