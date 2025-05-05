#include<stdio.h>
int main()
{
	int i,j;
	int s[10];
	for(i=0;i<10;i++){
		scanf("%d",&s[i]);
	}
	for(i=1;i<10;i++){
		if(s[i]!=0){
			printf("%d",i);
			s[i]--;
			break;//跳出此循环 确定首位1
		}
	}
	for(i=0;i<10;i++){
		for(j=s[i];j>0;j--){
			if(s[i]!=0) printf("%d",i);
		}
	}
	return 0;
}