#include<stdio.h>
int main()
{
    int n,i=1;
    scanf("%d",&n);
    if(n<0){
        n=-n;
    }
	while(n/10!=0){
		i++;
		n=n/10;
	}
    printf("It contains %d digits.",i);
    return 0;
}
